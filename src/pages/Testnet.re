module Styles = {
  open Css;

  let page =
    style([
      display(`flex),
      flexDirection(`column),
      overflowX(`hidden),
      height(`percent(100.)),
      height(`percent(100.)),
      selector("h4", [important(color(Theme.Colors.white))]),
    ]);

  let statusBadgeContainer =
    merge([
      Theme.Type.label,
      style([
        color(Theme.Colors.white),
        marginTop(`rem(4.5)),
        display(`flex),
        alignItems(`flexStart),
        flexDirection(`column),
        media(
          Theme.MediaQuery.tablet,
          [alignItems(`center), flexDirection(`row)],
        ),
      ]),
    ]);

  let statusBadge =
    style([
      marginTop(`rem(1.)),
      media(Theme.MediaQuery.tablet, [marginLeft(`rem(1.))]),
    ]);

  let leaderboardLink =
    style([width(`percent(100.)), textDecoration(`none)]);

  let leaderboardTextContainer =
    style([
      display(`flex),
      flexDirection(`column),
      alignItems(`flexStart),
      justifyContent(`center),
      marginTop(`rem(4.)),
      marginBottom(`rem(2.)),
      width(`percent(100.)),
      media(
        Theme.MediaQuery.notMobile,
        [
          width(`percent(50.)),
          alignItems(`flexStart),
          justifyContent(`flexStart),
        ],
      ),
      selector(
        "button",
        [
          marginTop(`rem(2.)),
          important(maxWidth(`percent(50.))),
          width(`percent(100.)),
        ],
      ),
    ]);

  let disclaimer =
    merge([
      Theme.Type.disclaimer,
      style([
        display(`listItem),
        listStylePosition(`inside),
        marginBottom(`rem(4.)),
        marginTop(`rem(3.)),
        media(Theme.MediaQuery.notMobile, [marginBottom(`rem(12.))]),
      ]),
    ]);

  let leaderboardContainer =
    style([
      height(`rem(65.)),
      width(`percent(100.)),
      position(`relative),
      overflow(`hidden),
      display(`flex),
      flexWrap(`wrap),
      marginLeft(`auto),
      marginRight(`auto),
      justifyContent(`center),
      media(Theme.MediaQuery.tablet, [height(`rem(43.))]),
    ]);
};

[@react.component]
let make = () => {
  <Page title="Mina Protocol">
    <div className=Styles.page>
      <div className=Nav.Styles.spacer />
      <Hero
        title="Testnet"
        header={Some("Secure the Network")}
        copy={
          Some(
            {j|Push the boundaries of Mina’s testnet to help prepare for mainnet.|j},
          )
        }
        background={
          Theme.desktop: "/static/img/TestnetBackground.jpg",
          tablet: "/static/img/TestnetBackground.jpg",
          mobile: "/static/img/TestnetBackground.jpg",
        }>
        <div className=Styles.statusBadgeContainer>
          <span> {React.string("Testnet Status: ")} </span>
          <span className=Styles.statusBadge>
            <StatusBadge service=`Network />
          </span>
        </div>
      </Hero>
      <Wrapped>
        <div className=Styles.leaderboardTextContainer>
          <h2 className=Theme.Type.h2>
            {React.string("Testnet Leaderboard")}
          </h2>
          <Spacer height=1. />
          <p className=Theme.Type.paragraphMono>
            {React.string(
               "Mina rewards community members for contributing to Testnet with Testnet Points, making them stronger applicants for the Genesis Program. ",
             )}
          </p>
          <Button
            width={`rem(12.5)}
            bgColor=Theme.Colors.orange
            href={`Internal("/leaderboard")}>
            {React.string("See The Full Leaderboard")}
            <Icon kind=Icon.ArrowRightSmall />
          </Button>
        </div>
        <div className=Styles.leaderboardContainer>
          <a href="/leaderboard" className=Styles.leaderboardLink>
            <Leaderboard interactive=false />
          </a>
        </div>
        <p className=Styles.disclaimer>
          {React.string(
             "Testnet Points are designed solely to track contributions to the Testnet and are non-transferable. Testnet Points have no cash or monetary value and are not redeemable for any cryptocurrency or digital assets. We may amend or eliminate Testnet Points at any time.",
           )}
        </p>
      </Wrapped>
      <FeaturedSingleRow
        row={
          FeaturedSingleRow.Row.rowType: ImageRightCopyLeft,
          copySize: `Small,
          title: "Testnet Challenges",
          description: "Learn how to operate the protocol, while contributing to Mina's network resilience.",
          textColor: Theme.Colors.white,
          image: "/static/img/TestnetCopyBackgroundDesktop.jpg",
          background: Image("/static/img/MinaSpectrumPrimarySilver.jpg"),
          contentBackground:
            Image("/static/img/TestnetContentBlockBackground.png"),
          link:
            FeaturedSingleRow.Row.Button({
              FeaturedSingleRow.Row.buttonText: "See the Latest Challenges",
              buttonColor: Theme.Colors.mint,
              buttonTextColor: Theme.Colors.digitalBlack,
              dark: true,
              href: `External(Constants.currentChallenges),
            }),
        }
      />
      <Wrapped> <TestnetRetroModule /> </Wrapped>
      <ButtonBar
        kind=ButtonBar.HelpAndSupport
        backgroundImg="/static/img/ButtonBarBackground.jpg"
      />
    </div>
  </Page>;
};
