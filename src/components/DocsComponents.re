module Styles = {
  open Css;

  let headerLink =
    style([
      display(`none),
      width(rem(1.)),
      height(rem(1.)),
      fontSize(`px(16)),
      lineHeight(`px(24)),
      marginLeft(rem(0.5)),
      color(`transparent),
      hover([color(`transparent)]),
      backgroundSize(`cover),
      backgroundImage(url("/static/img/link.svg")),
    ]);

  let h1Spacing = style([marginBottom(`rem(1.))]);

  let headerSpacing =
    merge([
      h1Spacing,
      style([marginTop(`rem(3.)), marginBottom(`rem(1.5))]),
    ]);

  let paragraphSpacing = style([marginBottom(`rem(1.5))]);

  let ruleSpacing = style([margin2(~v=`rem(3.), ~h=`zero)]);

  let code =
    style([
      Theme.Typeface.monumentGroteskMono,
      fontSize(`rem(1.)),
      lineHeight(`rem(1.5)),
      height(`percent(100.)),
    ]);

  let list =
    style([
      color(Theme.Colors.digitalBlack),
      Theme.Typeface.monumentGrotesk,
      fontSize(`rem(1.125)),
      lineHeight(`rem(1.6875)),
      marginTop(`rem(0.5)),
      marginBottom(`rem(1.)),
      marginLeft(`rem(2.6875)),
      selector("> :not(:first-child)", [marginTop(`rem(0.5))]),
      selector(
        "> li > img",
        [
          display(`flex),
          flexDirection(`column),
          justifyContent(`center),
          margin(`auto),
        ],
      ),
    ]);

  let link = style([textDecoration(`none)]);
};

module type Component = {let element: React.element;};

module Wrap = (C: Component) => {
  let make = props => {
    ReasonReact.cloneElement(C.element, ~props, [||]);
  };

  [@bs.obj] external makeProps: (~children: 'a, unit) => {. "children": 'a};
};

module WrapHeader = (C: Component) => {
  let make = props => {
    switch (Js.Undefined.toOption(props##id)) {
    | None => ReasonReact.cloneElement(C.element, ~props, [||])
    | Some(id) =>
      // Somewhat dangerously add a headerlink to the header's children
      let children =
        Js.Array.concat(
          [|
            <a
              className={"headerlink " ++ Styles.headerLink}
              href={"#" ++ id}
            />,
          |],
          [|props##children|],
        );
      ReasonReact.cloneElement(C.element, ~props, children);
    };
  };
};

open Css;

module H1 =
  WrapHeader({
    let element = <h1 className={merge([Styles.h1Spacing, Theme.Type.h1])} />;
  });

module H2 =
  WrapHeader({
    let element =
      <h2 className={merge([Styles.headerSpacing, Theme.Type.h2])} />;
  });

module H3 =
  WrapHeader({
    let element =
      <h3 className={merge([Styles.headerSpacing, Theme.Type.h3])} />;
  });

module H4 =
  WrapHeader({
    let element =
      <h4 className={merge([Styles.headerSpacing, Theme.Type.h4])} />;
  });

module P =
  Wrap({
    let element =
      <p
        className={merge([Styles.paragraphSpacing, Theme.Type.paragraph])}
      />;
  });

module A =
  Wrap({
    let element =
      <a
        target="_blank"
        rel="noopener"
        className={merge([Styles.link, Theme.Type.link])}
      />;
  });

module Strong =
  Wrap({
    let element = <strong className={style([fontWeight(`num(500))])} />;
  });

[@bs.scope ("navigator", "clipboard")] [@bs.val]
external writeText: string => Js.Promise.t(unit) = "writeText";

module Pre = {
  [@react.component]
  let make = (~children) => {
    let text =
      Js.String.trim(
        Js.String.make(
          (ReactExt.Children.only(children) |> ReactExt.props)##children,
        ),
      );
    <div className={style([position(`relative)])}>
      <div
        className={style([
          position(`absolute),
          top(`px(6)),
          right(`px(6)),
          width(`px(24)),
          height(`px(24)),
          height(`px(24)),
          opacity(0.2),
          cursor(`pointer),
          backgroundImage(
            `url(
              "data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iNTEyIiBoZWlnaHQ9IjUxMiIgdmlld0JveD0iMCAwIDUxMiA1MTIiIGZpbGw9Im5vbmUiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+CjxyZWN0IHdpZHRoPSI1MTIiIGhlaWdodD0iNTEyIiAvPgo8cGF0aCBmaWxsLXJ1bGU9ImV2ZW5vZGQiIGNsaXAtcnVsZT0iZXZlbm9kZCIgZD0iTTMwMSAxMzBIMTUzVjM3MUgxMzdWMTIyQzEzNyAxMTcuNTgyIDE0MC41ODIgMTE0IDE0NSAxMTRIMzAxVjEzMFpNMTg2IDM4NlYxNjJIMzI2VjM4NkgxODZaTTE3MCAxNTRDMTcwIDE0OS41ODIgMTczLjU4MiAxNDYgMTc4IDE0NkgzMzRDMzM4LjQxOCAxNDYgMzQyIDE0OS41ODIgMzQyIDE1NFYzOTRDMzQyIDM5OC40MTggMzM4LjQxOCA0MDIgMzM0IDQwMkgxNzhDMTczLjU4MiA0MDIgMTcwIDM5OC40MTggMTcwIDM5NFYxNTRaIiBmaWxsPSJibGFjayIvPgo8L3N2Zz4K",
            ),
          ),
          backgroundSize(`cover),
          hover([opacity(0.7)]),
        ])}
        onClick={_ => {
          // TODO: Change copy icon to checkmark or something when copy
          writeText(text)
          |> Promise.iter(() => {Js.log("copied")})
        }}
      />
      <pre
        className={style([
          backgroundColor(Theme.Colors.digitalBlack),
          borderRadius(`px(4)),
          padding2(~v=`rem(1.), ~h=`rem(1.)),
          overflow(`scroll),
          selector("code", [color(Theme.Colors.white)]),
        ])}>
        children
      </pre>
    </div>;
  };
};

module Code =
  Wrap({
    let element = <code className=Styles.code />;
  });

module Ul =
  Wrap({
    let element = <ul className=Styles.list />;
  });

module Al =
  Wrap({
    let element = <ol type_="a" className=Styles.list />;
  });

module Ol =
  Wrap({
    let element = <ol className=Styles.list />;
  });

module Img =
  Wrap({
    let element = <img />;
  });

module Rule =
  WrapHeader({
    let element = <div className=Styles.ruleSpacing> <Rule /> </div>;
  });

module DaemonCommandExample = {
  let defaultArgs = ["mina daemon", "-peer-list ~/peers.txt"];
  [@react.component]
  let make = (~args: array(string)=[||]) => {
    let allArgs = defaultArgs @ Array.to_list(args);
    let argsLength =
      List.fold_left((a, e) => a + String.length(e), 0, allArgs);
    let sep = argsLength > 60 ? " \\\n    " : " ";
    let processedArgs =
      String.concat(sep, defaultArgs @ Array.to_list(args));
    <Pre> <Code> {React.string(processedArgs)} </Code> </Pre>;
  };
};

module Blog = {
  module Styles = {
    let spacing = style([padding2(~v=`rem(1.), ~h=`zero)]);
  };

  module Img =
    Wrap({
      let element = <img className=Styles.spacing />;
    });
};

let allComponents = () => {
  "Alert": Alert.make,
  "DaemonCommandExample": DaemonCommandExample.make,
  "h1": H1.make,
  "h2": H2.make,
  "h3": H3.make,
  "h4": H4.make,
  "p": P.make,
  "a": A.make,
  "strong": Strong.make,
  "pre": Pre.make,
  "code": Code.make,
  "al": Al.make,
  "ul": Ul.make,
  "ol": Ol.make,
  "img": Img.make,
  "Rule": Rule.make,
  "Footnote": Footnote.make,
};
