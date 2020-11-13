// TODO: Abstract this component to take all ListModule.itemKinds
module FeaturedPress = {
  module Styles = {
    open Css;

    let gridContainer =
      style([
        display(`grid),
        gridTemplateColumns([`repeat((`num(2), `fr(1.)))]),
        gridColumnGap(`rem(1.)),
      ]);
    let container =
      style([
        display(`flex),
        flexDirection(`column),
        display(`grid),
        borderTop(`px(1), `solid, Theme.Colors.digitalBlack),
        width(`percent(100.)),
        media(Theme.MediaQuery.notMobile, [width(`percent(80.))]),
      ]);

    let mainListingContainerImage =
      style([
        display(`flex),
        justifyContent(`spaceBetween),
        width(`percent(100.)),
      ]);

    let mainListingContainer =
      style([
        display(`flex),
        justifyContent(`flexStart),
        alignItems(`flexStart),
        width(`percent(100.)),
        marginBottom(`rem(4.)),
      ]);

    let mainListing =
      style([
        display(`flex),
        flexDirection(`column),
        height(`percent(100.)),
        width(`percent(100.)),
        maxWidth(`rem(30.)),
      ]);

    let metadata =
      merge([Theme.Type.metadata, style([marginTop(`rem(0.5))])]);

    let link =
      merge([
        Theme.Type.buttonLink,
        style([
          display(`flex),
          alignItems(`center),
          cursor(`pointer),
          marginTop(`auto),
          marginBottom(`rem(2.)),
          textDecoration(`none),
        ]),
      ]);

    let title =
      merge([
        Theme.Type.h5,
        style([fontWeight(`light), marginTop(`rem(1.))]),
      ]);

    let image =
      style([
        marginBottom(`rem(4.)),
        marginRight(`rem(4.)),
        width(`rem(35.)),
        height(`rem(23.)),
      ]);
  };

  let run = () => {
    Contentful.getEntries(
      Lazy.force(Contentful.client),
      {"include": 1, "content_type": ContentType.Press.id},
    )
    |> Promise.map((entries: ContentType.Press.entries) => {
         Array.map((e: ContentType.Press.entry) => e.fields, entries.items)
       });
  };

  [@react.component]
  let make = () => {
    let (content, setContent) = React.useState(_ => [||]);

    React.useEffect0(() => {
      run() |> Promise.iter(press => {setContent(_ => press)});
      None;
    });

    let renderMainListing = (item: ContentType.Press.t) => {
      let {
        ContentType.Press.datePublished,
        publisher,
        description,
        link,
        image,
      } = item;

      let containerCss =
        Belt.Option.mapWithDefault(image, Styles.mainListingContainer, _ => {
          Styles.mainListingContainerImage
        });

      <div className=containerCss>
        {Belt.Option.mapWithDefault(image, React.null, image => {
           <> <img src={image.fields.file.url} className=Styles.image /> </>
         })}
        <div className=Styles.mainListing>
          <div className=Styles.metadata>
            <span> {React.string("Press")} </span>
            <span> {React.string(" / ")} </span>
            <span> {React.string(datePublished)} </span>
            <span> {React.string(" / ")} </span>
            <span> {React.string(publisher)} </span>
          </div>
          <h5 className=Styles.title> {React.string(item.title)} </h5>
          {ReactExt.fromOpt(
             Js.Undefined.toOption(description), ~f=description =>
             <>
               <Spacer height=1. />
               <p className=Theme.Type.paragraph>
                 {React.string(description)}
               </p>
             </>
           )}
          <Spacer height=2.5 />
          <Button href={`External(link)}>
            <span> {React.string("Read more")} </span>
            <Icon kind=Icon.ArrowRightSmall />
          </Button>
        </div>
      </div>;
    };

    let renderListing = (item: ContentType.Press.t) => {
      let {ContentType.Press.title, datePublished, publisher, link} = item;
      <div className=Styles.container key=title>
        <div className=Styles.metadata>
          <span> {React.string("Press")} </span>
          <span> {React.string(" / ")} </span>
          <span> {React.string(datePublished)} </span>
          <span> {React.string(" / ")} </span>
          <span> {React.string(publisher)} </span>
        </div>
        <h5 className=Styles.title> {React.string(title)} </h5>
        <a href=link className=Styles.link>
          <span> {React.string("Read more")} </span>
          <Icon kind=Icon.ArrowRightSmall />
        </a>
      </div>;
    };

    content->Array.length == 0
      ? React.null
      : <Wrapped>
          <h2 className=Theme.Type.h2> {React.string("Featured Press")} </h2>
          <Spacer height=4. />
          {content[0]->renderMainListing}
          <div className=Styles.gridContainer>
            {content->Belt.Array.slice(~offset=1, ~len=Array.length(content))
             |> Array.map((item: ContentType.Press.t) => {
                  item->renderListing
                })
             |> React.array}
          </div>
        </Wrapped>;
  };
};

module Styles = {
  open Css;
  let featuredPressSection =
    style([
      backgroundImage(`url("/static/img/BackgroundGlowCluster01.jpg")),
      backgroundSize(`cover),
      padding2(~v=`rem(6.), ~h=`zero),
    ]);
};

[@react.component]
let make = () => {
  <Page title="Mina Cryptocurrency Protocol" footerColor=Theme.Colors.orange>
    <div className=Nav.Styles.spacer />
    <Hero
      title=""
      header={Some("Press & Media")}
      copy={
        Some(
          "Light. Accessible. Decentralized. SNARKy. Mina is a whole new kind of blockchain.",
        )
      }
      background={
        Theme.desktop: "/static/img/backgrounds/PressAndMediaDesktop.jpg",
        Theme.tablet: "/static/img/backgrounds/PressAndMediaTablet.jpg",
        Theme.mobile: "/static/img/backgrounds/15_PressandMedia_1_750x1056_mobile.jpg",
      }>
      <Spacer height=1.5 />
      <Button
        href={`External(Constants.minaPressKit)}
        bgColor=Theme.Colors.black
        width={`rem(14.)}>
        {React.string("Download Media Kit")}
        <Icon kind=Icon.ArrowRightMedium size=1. />
      </Button>
    </Hero>
    <div className=Styles.featuredPressSection> <FeaturedPress /> </div>
  </Page>;
};
