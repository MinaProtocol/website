// Siplified from https://gist.github.com/joshuacerbito/ea318a6a7ca4336e9fadb9ae5bbb87f4
[@bs.val][@bs.scope("window")] external scrollY: int = "scrollY";

[@bs.val]
external addScrollListener: ([@bs.as "scroll"] _, Dom.event => unit) => unit =
  "addEventListener";
[@bs.val]
external removeScrollListener: ([@bs.as "scroll"] _, Dom.event => unit) => unit =
  "removeEventListener";

let useScroll = () => {
  let (bodyOffset, setBodyOffset) = React.useState(() => 0);

  let listener = _ => setBodyOffset(_ => scrollY);

  React.useEffect0(() => {
    addScrollListener(listener);
    Some(() => {removeScrollListener(listener)});
  });

  bodyOffset;
};

let useOnScreen = (~options, ()) => {
  open ReactExt.IntersectionObserver;
  let currentRef = React.useRef(Js.Nullable.null);
  let (visible, setVisible) = React.useState(() => false);

  React.useEffect2(
    () => {
      let observer =
        newIntersectionObserver(
          ~cb=
            (entries, _) => {
              entries
              ->Belt.Array.map(entry => setVisible(_ => entry.isIntersecting))
              ->ignore;
              ();
            },
          ~options,
        );

      let currentRef = Js.Nullable.toOption(currentRef.current);
      Belt.Option.forEach(currentRef, ref_ => {observe(observer, ref_)});

      Some(
        () => {
          Belt.Option.forEach(currentRef, ref_ => {unobserve(observer, ref_)})
        },
      );
    },
    (currentRef, visible),
  );
  (currentRef, visible);
};

let useOnScreenWidth = () => {
  let (width, setWidth) = React.useState(() => 0);

  React.useEffect0(() => {
    let handleSize = () => {
      setWidth(_ => ReactExt.Window.innerWidth);
    };
    ReactExt.Window.addEventListener("resize", handleSize);
    handleSize();

    Some(() => {ReactExt.Window.removeEventListener("resize", handleSize)});
  });
  width;
};
