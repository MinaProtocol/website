module Styles = {
  open Css;
  let page =
    style([
      display(`flex),
      flexDirection(`column),
      overflowX(`hidden),
      height(`percent(100.)),
      height(`percent(100.)),
    ]);
};

[@react.component]
let make = () => {
  <Page title="Mina Protocol" footerColor=Theme.Colors.orange>
    <div className=Styles.page>
      <HomepageHero backgroundImg="/static/img/HeroSectionBackground.jpg" />
      <BlockchainComparison />
      <AlternatingSections
        backgroundImg="/static/img/MinaSimplePattern1.jpg"
        sections={
          AlternatingSections.Section.FeaturedRow([|
            {
              AlternatingSections.Section.FeaturedRow.title: "Easily Accessible, Now & Always",
              description:
                <div
                  className=AlternatingSections.Section.SectionStyles.paragraphText>
                  <span>
                    {React.string(
                       {js|Other protocols are so heavy they require intermediaries to run nodes, recreating the same old power dynamics. But Mina is light, so anyone can connect peer-to-peer and quickly sync and verify the chain. Built on a consistent-sized cryptographic proof, the blockchain will stay accessible—even as it scales.|js},
                     )}
                  </span>
                </div>,
              linkCopy: "Explore the Tech",
              linkUrl: "/tech",
              image: "/static/img/EasilyAccessible.png",
            },
            {
              title: "Truly Decentralized, with Every User Acting as a Full Node",
              description:
                <div
                  className=AlternatingSections.Section.SectionStyles.paragraphText>
                  <span>
                    {React.string(
                       "With Mina, anyone who's syncing the chain is also validating transactions like a full node. Mina's design means any participant can take part in proof-of-stake consensus, have access to strong censorship-resistance and secure the blockchain.",
                     )}
                  </span>
                </div>,
              linkCopy: "Run a Node",
              linkUrl: "/docs/node-operator",
              image: "/static/img/TrulyDecentralized.png",
            },
            {
              title: "Dapps, Where People Control Their Data",
              description:
                <div
                  className=AlternatingSections.Section.SectionStyles.paragraphText>
                  <span>
                    {React.string(
                       {js|Today, users have no alternative to handing over their data to powerful players in exchange for participation in the modern world. But Mina’s SNARK-powered decentralized apps (Snapps) keep users in control by validating and sharing proofs about their data — rather than the data itself. Even to counterparties. And with logic and data computed off-chain and verified on-chain, Snapps make scalability simple and large computations efficient and cost-effective.|js},
                     )}
                  </span>
                </div>,
              linkCopy: "Learn about Snapps",
              linkUrl: "/docs/architecture/snapps",
              image: "/static/img/PrivateAndPowerful.png",
            },
            {
              title: "A Private Gateway to the Real World ",
              description:
                <div
                  className=AlternatingSections.Section.SectionStyles.paragraphText>
                  <span>
                    {React.string(
                       {js|Other blockchains don’t interact with the internet, limiting their applications’ scope and utility.  But Mina’s Snapps can privately interact with any website and access verified real world data for use on-chain. So developers can leverage the world’s information in computing and decision-making to change the way we live and work — without ever compromising privacy.|js},
                     )}
                  </span>
                </div>,
              linkCopy: "Learn More",
              linkUrl: "/tech#projects",
              image: "/static/img/private-gateway-transparent.png",
            },
            {
              title: "Powered by a Growing Community",
              description:
                <div
                  className=AlternatingSections.Section.SectionStyles.paragraphText>
                  <p>
                    {React.string(
                       {js|Other blockchains are run by powerful ecosystem intermediaries. But Mina is powered by participants, with an uncapped number of block producers. Our inclusive community unites people around the world with a passion for decentralized blockchain. In fact, we have one of the largest and most active communities of any project launched in the last two years.|js},
                     )}
                  </p>
                </div>,
              linkCopy: "Join our Community",
              linkUrl: "/community",
              image: "/static/img/community-powered-transparent.png",
            },
          |])
        }
      />
      <FeaturedSingleRow
        row={
          FeaturedSingleRow.Row.rowType: ImageLeftCopyRight,
          title: "It's Time to Own Our Future",
          copySize: `Small,
          description: "Why did we create the world's lightest blockchain? To rebalance the scales and give anyone with a smartphone the power to participate, build, exchange and thrive.",
          textColor: Theme.Colors.digitalBlack,
          image: "/static/img/homepage-cta.jpg",
          background: Image("/static/img/MinaSpectrumPrimary3.jpg"),
          contentBackground: Color(Theme.Colors.white),
          link:
            FeaturedSingleRow.Row.Button({
              FeaturedSingleRow.Row.buttonText: "More on Mina",
              buttonColor: Theme.Colors.orange,
              buttonTextColor: Theme.Colors.white,
              dark: false,
              href: `Internal("/about"),
            }),
        }
      />
      <Wrapped>
        <BlogModule
          source=`Announcement
          title="Mina Announcements"
          itemKind=ListModule.Announcement
          buttonHref={`Internal("/announcements")}
        />
        <BlogModule
          source=`Press
          itemKind=ListModule.Press
          buttonHref={`Internal("/media")}
        />
      </Wrapped>
    </div>
  </Page>;
};
