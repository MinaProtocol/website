open Css;

module Styles = {
  let heroContainer = (backgroundImg: Theme.backgroundImage) =>
    style([
      height(`rem(37.)),
      display(`flex),
      flexDirection(`column),
      justifyContent(`flexEnd),
      alignContent(`spaceBetween),
      backgroundImage(`url(backgroundImg.mobile)),
      backgroundSize(`cover),
      media(
        Theme.MediaQuery.tablet,
        [
          justifyContent(`flexStart),
          height(`percent(100.)),
          backgroundImage(`url(backgroundImg.tablet)),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [backgroundImage(`url(backgroundImg.desktop))],
      ),
    ]);
  let marginX = x => [marginLeft(x), marginRight(x)];
  let heroContent =
    style(
      [marginTop(`rem(4.2)), marginBottom(`rem(4.0))]
      @ marginX(`rem(1.25))
      @ [
        media(
          Theme.MediaQuery.tablet,
          [
            marginTop(`rem(7.)),
            marginBottom(`rem(6.5)),
            ...marginX(`rem(2.5)),
          ],
        ),
        media(
          Theme.MediaQuery.desktop,
          [
            marginTop(`rem(17.1)),
            marginBottom(`rem(8.)),
            ...marginX(`rem(9.5)),
          ],
        ),
      ],
    );
  let headerLabel =
    merge([
      Theme.Type.label,
      style([
        color(black),
        marginTop(`zero),
        marginBottom(`zero),
        fontWeight(`light),
      ]),
    ]);
  let header =
    merge([
      Theme.Type.h1,
      style([
        backgroundColor(white),
        marginRight(`rem(1.)),
        padding2(~v=`rem(1.3), ~h=`rem(1.3)),
        unsafe("width", "max-content"),
        media(
          Theme.MediaQuery.desktop,
          [padding2(~v=`rem(1.5), ~h=`rem(1.5))],
        ),
        marginTop(`rem(1.)),
        marginBottom(`rem(1.5)),
      ]),
    ]);
  let headerCopy =
    merge([
      Theme.Type.pageSubhead,
      style([
        backgroundColor(white),
        padding2(~v=`rem(1.5), ~h=`rem(1.5)),
        marginRight(`rem(1.)),
        marginTop(`zero),
        marginBottom(`zero),
        width(`percent(100.)),
        media(Theme.MediaQuery.tablet, [maxWidth(`rem(40.))]),
      ]),
    ]);

  let categoryDateSourceContainer =
    style([
      borderTop(`px(1), `solid, Theme.Colors.digitalBlack),
      marginTop(`rem(1.)),
      paddingTop(`rem(1.)),
      paddingBottom(`rem(0.5)),
    ]);
};

/**
 * This component takes in three different background images, as per Mina's design.
 */

[@react.component]
let make =
    (
      ~title=?,
      ~metadata=None,
      ~header: option(string),
      ~copy,
      ~background: Theme.backgroundImage,
      ~children=?,
    ) => {
  <div className={Styles.heroContainer(background)}>
    <div className=Styles.heroContent>
      {ReactExt.fromOpt(title, ~f=s =>
         <h4 className=Styles.headerLabel> {React.string(s)} </h4>
       )}
      {ReactExt.fromOpt(metadata, ~f=metadata =>
         <div className=Styles.categoryDateSourceContainer>
           <CategoryDateSourceText metadata />
         </div>
       )}
      {ReactExt.fromOpt(header, ~f=s =>
         <h1 className=Styles.header> {React.string(s)} </h1>
       )}
      {ReactExt.fromOpt(copy, ~f=s =>
         <p className=Styles.headerCopy> {React.string(s)} </p>
       )}
      {switch (children) {
       | Some(children) => children
       | None => React.null
       }}
    </div>
  </div>;
};
