// This is the layout for the docs MDX pages

module Style = {
  open! Css;

  let content =
    style([
      width(`percent(100.)),
      maxWidth(`rem(30.)),
      marginBottom(`rem(2.875)),
      media(
        Theme.MediaQuery.notMobile,
        [maxWidth(`rem(53.)), marginLeft(`rem(1.))],
      ),
      selector("p > code, li > code", Theme.Type.inlineCode_),
      selector("h1 + p", Theme.Type.sectionSubhead_),
    ]);

  let page =
    style([
      display(`flex),
      justifyContent(`center),
      margin(`auto),
      marginTop(`rem(2.)),
      paddingBottom(`rem(6.)),
      media(Theme.MediaQuery.desktop, [justifyContent(`spaceBetween)]),
    ]);

  let blogBackground =
    style([
      height(`percent(100.)),
      width(`percent(100.)),
      important(backgroundSize(`cover)),
      backgroundImage(`url("/static/img/backgrounds/BlogBackground.jpg")),
    ]);

  let eyebrow = style([marginBottom(`rem(1.))]);

  let editLink =
    style([
      display(`none),
      textDecoration(`none),
      color(Theme.Colors.orange),
      media(
        Theme.MediaQuery.notMobile,
        [marginLeft(`rem(1.5)), display(`flex), alignItems(`center)],
      ),
    ]);

  let editLink__icon =
    style([display(`flex), alignItems(`center), marginLeft(`rem(0.5))]);

  let statusBadgeContainer =
    merge([
      Theme.Type.label,
      style([
        display(`flex),
        alignItems(`flexStart),
        flexDirection(`column),
        marginTop(`rem(-3.)),
        media(
          Theme.MediaQuery.tablet,
          [marginTop(`zero), alignItems(`flexStart), flexDirection(`row)],
        ),
      ]),
    ]);

  let statusBadge =
    style([
      media(
        Theme.MediaQuery.tablet,
        [marginTop(`rem(-1.)), marginLeft(`rem(1.))],
      ),
    ]);

  let statusBadge__header =
    merge([
      Theme.Type.h4,
      style([
        paddingBottom(`rem(1.)),
        media(Theme.MediaQuery.notMobile, [paddingBottom(`zero)]),
      ]),
    ]);

  let content__button =
    style([
      display(`block),
      media(Theme.MediaQuery.notMobile, [display(`none)]),
    ]);

  let content__flex =
    style([
      display(`flex),
      width(`percent(100.)),
      justifyContent(`spaceBetween),
      alignItems(`flexStart),
    ]);

  let content__row =
    style([
      width(`rem(15.)),
      height(`rem(7.)),
      display(`flex),
      justifyContent(`spaceBetween),
      flexDirection(`column),
      marginBottom(`rem(1.5)),
      media(
        Theme.MediaQuery.notMobile,
        [marginBottom(`zero), alignItems(`flexStart), flexDirection(`row)],
      ),
    ]);
};

module EditLink = {
  [@react.component]
  let make = (~route) => {
    <a
      name="Edit Link"
      target="_blank"
      rel="noopener"
      href={Constants.minaDocsEditLink ++ route ++ ".mdx"}
      className=Style.editLink>
      <span className=Theme.Type.link> {React.string("Edit ")} </span>
      <span className=Style.editLink__icon>
        <Icon kind=Icon.ArrowRightMedium />
      </span>
    </a>;
  };
};

type metadata = {title: string};

[@react.component]
let make = (~metadata, ~children) => {
  let router = Next.Router.useRouter();
  let currentSlug =
    if (router.route == "/docs") {
      "/docs";
    } else {
      Js.String.replaceByRe(
        Js.Re.fromString("^/docs/?"),
        "/docs/",
        router.route,
      );
    };

  let renderStatusBadge = () => {
    <span className=Style.statusBadgeContainer>
      <h4 className=Style.statusBadge__header>
        {React.string("Network Status: ")}
      </h4>
      <span className=Style.statusBadge>
        <StatusBadge service=`Network />
      </span>
    </span>;
  };

  let renderMobileEditButton = () => {
    <span className=Style.content__button>
      <Button
        width={`rem(7.25)}
        href={`External(Constants.minaDocsEditLink ++ router.route ++ ".mdx")}
        bgColor=Theme.Colors.orange>
        {React.string("Edit")}
        <Icon kind=Icon.ArrowRightSmall />
      </Button>
    </span>;
  };

  <Page title={metadata.title}>
    <Next.Head>
      <link rel="stylesheet" href="/static/css/a11y-light.css" />
      Markdown.katexStylesheet
    </Next.Head>
    <div className=Style.blogBackground>
      <Wrapped>
        <div className=Nav.Styles.spacer />
        <div className=Style.page>
          <DocsNavs.SideNav currentSlug />
          <div className=Style.content>
            <DocsNavs.Dropdown currentSlug />
            <div className=Style.content__flex>
              <span className=Style.content__row>
                {renderMobileEditButton()}
                <h4 className=Theme.Type.h4>
                  {React.string("Documentation")}
                </h4>
                <EditLink route={router.route} />
              </span>
              {renderStatusBadge()}
            </div>
            <Next.MDXProvider components={DocsComponents.allComponents()}>
              children
            </Next.MDXProvider>
          </div>
        </div>
      </Wrapped>
    </div>
  </Page>;
};

let default =
  (. metadata) =>
    (. props: {. "children": React.element}) =>
      make({"metadata": metadata, "children": props##children});
