module Styles = {
  open Css;
  let page =
    style([
      marginLeft(`auto),
      marginRight(`auto),
      display(`flex),
      width(`percent(100.)),
      flexDirection(`column),
      justifyContent(`spaceBetween),
      alignContent(`spaceAround),
      media(Theme.MediaQuery.tablet, [maxWidth(`rem(68.))]),
    ]);

  let container =
    style([
      height(`rem(40.)),
      display(`flex),
      flexDirection(`column),
      justifyContent(`spaceBetween),
    ]);
  let documentationButton =
    style([textAlign(`left), height(`rem(2.)), width(`rem(7.18))]);
  let joinGenesisButton =
    style([color(white), width(`rem(5.75)), height(`rem(2.))]);
};

[@react.component]
let make = () => {
  <Page title="Demo page of components">
    <div className=Nav.Styles.spacer />
    <div className=Styles.page>
      <div>
        <SideNav currentSlug="">
          <SideNav.Item title="Overview" slug="" />
          <SideNav.Item title="Getting Started" slug="getting-started" />
          <SideNav.Section title="Developers" slug="developers">
            <SideNav.Item title="Developers Overview" slug="" />
            <SideNav.Item title="Codebase Overview" slug="codebase-overview" />
          </SideNav.Section>
          <SideNav.Section title="SNARKs" slug="snarks">
            <SideNav.Item title="SNARKs Overview" slug="" />
          </SideNav.Section>
          <SideNav.Item title="Archive Node" slug="archive-node" />
          <SideNav.Item title="Snapps" slug="snapps" />
          <SideNav.Item title="Glossary" slug="glossary" />
        </SideNav>
      </div>
      <div className=Styles.container>
        /*** Regular buttons */

          <Button href=`Scroll_to_top bgColor=Theme.Colors.orange>
            {React.string("Button Label")}
            <Icon kind=Icon.ArrowRightMedium />
          </Button>
          <Button href=`Scroll_to_top bgColor=Theme.Colors.mint dark=true>
            {React.string("Button label ")}
            <Icon kind=Icon.ArrowRightMedium />
          </Button>
          <Button href=`Scroll_to_top bgColor=Theme.Colors.black>
            {React.string("Button label")}
            <Icon kind=Icon.ArrowRightMedium />
          </Button>
          <Button href=`Scroll_to_top bgColor=Theme.Colors.white>
            {React.string("Button label")}
            <Icon kind=Icon.ArrowRightMedium />
          </Button>
          /*** Documentation Button TODO: Add link for documentation */
          <PromoButton bgColor=Theme.Colors.orange>
            <Icon kind=Icon.Documentation size=2.5 />
            <span className=Styles.documentationButton>
              {React.string("Go To Documentation")}
            </span>
          </PromoButton>
          /***Join Genesis Button, uses the CoreProtocolLarge icon */
          <Button
            href=`Scroll_to_top
            bgColor=Theme.Colors.orange
            paddingX=1.
            paddingY=0.5>
            <Icon kind=Icon.CoreProtocolLarge size=2.5 />
            <span className=Styles.joinGenesisButton>
              {React.string("Join Genesis + Earn Mina")}
            </span>
          </Button>
        </div>
      <h1 className=Theme.Type.h1jumbo> {React.string("H1 Jumbo")} </h1>
      <h1 className=Theme.Type.h1> {React.string("H1")} </h1>
      <h2 className=Theme.Type.h2> {React.string("H2")} </h2>
      <h3 className=Theme.Type.h3> {React.string("H3")} </h3>
      <h4 className=Theme.Type.h4> {React.string("H4")} </h4>
      <h5 className=Theme.Type.h4> {React.string("H5")} </h5>
      <h6 className=Theme.Type.h4> {React.string("H6")} </h6>
      <div className=Theme.Type.pageLabel> {React.string("Page label")} </div>
      <div className=Theme.Type.label> {React.string("Label")} </div>
      <div className=Theme.Type.buttonLabel>
        {React.string("Button label")}
      </div>
      <a className=Theme.Type.link> {React.string("Link")} </a>
      <a className=Theme.Type.navLink> {React.string("Nav Link")} </a>
      <a className=Theme.Type.sidebarLink> {React.string("Sidebar Link")} </a>
      <div className=Theme.Type.tooltip> {React.string("Tooltip")} </div>
      <div className=Theme.Type.creditName>
        {React.string("Credit name")}
      </div>
      <div className=Theme.Type.metadata> {React.string("Metadata")} </div>
      <div className=Theme.Type.announcement>
        <AnnouncementBar/>
      </div>
      <div className=Theme.Type.reward>
        <RewardsPromo />
      </div>
      <div className=Theme.Type.testworld> 
        <TestworldChallenges.Header title="Technical Challenges">  
        <TestworldChallenges.Contanier title1="BLOCK PRODUCTION" title2="REWARDS">
          <TestworldChallenges.Item 
            title="Be a Top Block Producer"
            rewardsMain="5% of MINA Foundation Treasury"
            rewardsSub="Delegated to you at mainnet. Grow your stake with our help."
          >
            <TestworldChallenges.Accordian>
              <TestworldChallenges.RewardsTable
                title="REWARDS"
                tableHead=[|"RESULT","DELEGATION"|]
                tableRow=[|"Top 20 Block Producers", "5% of MINA Foundation Treasury" |]
              />
              <TestworldChallenges.List
                title="RULES"
                rules=[|"The MINA foundation is expected to delegate 100% of its tokens post-mainnet to Testworld's top block producers.", "Testworld's top 20 block producing nodes will receive equal delegation.", "Each node will be delegated 5% of Foundation tokens.", "Selection criteria will be based on a combination of uptime & blocks produced."|]
              />
              <TestworldChallenges.List
                title="Applying For Delegation"
                rules=[|"Block producers will need to apply after Testworld to indicate interest in receiving delegation.", "Nodes must be staking no more than 8% of total Mina tokens available"|]
              />
              <TestworldChallenges.List
                title="Please Note"
                rules=[|"The Foundation will redelegate if uptime is unsatisfactory.", "No fees on Foundation delegation are allowed for three months.", "Block producers that are investors or employees of O(1) Labs will not eligible for Foundation delegation."|]
              />
              <TestworldChallenges.List
                title="Global Rules"
                rules=[|"Limit one wallet address per participant", "Limit one use of the faucet per participant", "If multiple participants are working together as a team, that team is limited to one wallet address, and one use of the faucet", "If multiple wallet addresses are used, only one address will be counted by our judges", "Node setup instructions are available in our documentation."|]
              />
              <TestworldChallenges.Link title="Docs: Getting Started"/>
              <TestworldChallenges.ContainerSm>
                <Button href=`Scroll_to_top  bgColor=Theme.Colors.mint dark=true>
                    {React.string("TELL US YOUR APPROACH")}
                    <Icon kind=Icon.ArrowRightMedium />
                </Button>
              </TestworldChallenges.ContainerSm>
            </TestworldChallenges.Accordian>
          </TestworldChallenges.Item>

          <TestworldChallenges.Item 
            title="Accumulate Testnet Tokens"
            rewardsMain="Earn up to 40,000 MINA tokens"
            rewardsSub="Distributed after mainnet launch."
          >
            <TestworldChallenges.Accordian>
              <TestworldChallenges.RewardsTable
                title="REWARDS"
                tableHead=[|"RESULT","MINA TOKENS"|]
                tableRow=[|"1st place", "40,000", "2nd place", "20,000", "3rd place", "10,000", "Top 10", "5,000", "Top 20", "2,000" |]
              />
              <TestworldChallenges.List
                title="RULES"
                rules=[|"Find unconventional way(s) to optimize your earnings", "Tokens can only be earned via block production", "Look for approaches and strategies that could work on mainnet. If you're confident your strategy would only work on testnet, it's not worth trying. "|]
              />
              <TestworldChallenges.List
                title="Global Rules"
                rules=[|"Limit one wallet address per participant", "Limit one use of the faucet per participant", "If multiple participants are working together as a team, that team is limited to one wallet address, and one use of the faucet", "If multiple wallet addresses are used, only one address will be counted by our judges", "Node setup instructions are available in our documentation."|]
              />
              <TestworldChallenges.Link title="Docs: Getting Started"/>
              <TestworldChallenges.ContainerSm>
                <Button bgColor=Theme.Colors.mint dark=true
                  href={`External(Constants.blockProductionTestnetToken)}>
                    {React.string("TELL US YOUR APPROACH")}
                    <Icon kind=Icon.ArrowRightMedium />
                </Button>
              </TestworldChallenges.ContainerSm>
              <TestworldChallenges.List
                title="Tell Us How You Did It"
                rules=[|"What was your unique approach?", "Max 200 words", "Don't worry about grammar"|]
              />
            </TestworldChallenges.Accordian>
          </TestworldChallenges.Item>
          <TestworldChallenges.Item 
            title="Produce Blocks"
            rewardsMain="Earn up to 6,500 *Testnet Points*"
            rewardsSub="Level up on the leaderboard, to get invited to our Genesis program."
          >
            <TestworldChallenges.Accordian>
              <TestworldChallenges.RewardsTable
                title="REWARDS"
                tableHead=[|"RESULT","*TESTNET POINTS"|]
                tableRow=[|"1st place", "6500", "2nd place", "5000", "3rd place", "4000", "Top 10", "3000", "Top 20", "2500", "Top 100", "1500", "Top 200", "1000" |]
              />
              <TestworldChallenges.ProduceBlockRules title="RULES" />
              <TestworldChallenges.List
                title="Global Rules"
                rules=[|"Limit one wallet address per participant", "Limit one use of the faucet per participant", "If multiple participants are working together as a team, that team is limited to one wallet address, and one use of the faucet", "If multiple wallet addresses are used, only one address will be counted by our judges", "Node setup instructions are available in our documentation."|]
              />
              <TestworldChallenges.Link title="Docs: Getting Started"/>
            </TestworldChallenges.Accordian>
          </TestworldChallenges.Item>
        </TestworldChallenges.Contanier>
        

        <TestworldChallenges.Contanier title1="SNARK PRODUCTION" title2="REWARDS">
          <TestworldChallenges.Item 
            title="Accumulate Testnet Tokens"
            rewardsMain="Earn up to 40,000 MINA Tokens"
            rewardsSub="Distributed after mainnet launch."
          >
            <TestworldChallenges.Accordian>
              <TestworldChallenges.RewardsTable
                title="REWARDS"
                tableHead=[|"RESULT","MINA TOKENS"|]
                tableRow=[|"1st place", "40,000", "2nd place", "20,000", "3rd place", "10,000", "Top 10", "5,000", "Top 20", "2,000"|]
              />
              <TestworldChallenges.List
                title="RULES"
                rules=[|"Find unconventional way(s) to optimize your earnings", "Tokens can only be earned via SNARK production", "Look for approaches and strategies that could work on mainnet. If you're confident your strategy would only work on testnet, it's not worth trying. "|]
              />
              <TestworldChallenges.List
                title="Global Rules"
                rules=[|"Limit one wallet address per participant", "Limit one use of the faucet per participant", "If multiple participants are working together as a team, that team is limited to one wallet address, and one use of the faucet", "If multiple wallet addresses are used, only one address will be counted by our judges", "Node setup instructions are available in our documentation."|]
              />
              <TestworldChallenges.Link title="Docs: Getting Started"/>
              <TestworldChallenges.ContainerSm>
                <Button bgColor=Theme.Colors.mint dark=true 
                  href={`External(Constants.snarkProductionTestnetToken)}>
                    {React.string("TELL US YOUR APPROACH")}
                    <Icon kind=Icon.ArrowRightMedium />
                </Button>
              </TestworldChallenges.ContainerSm>
              <TestworldChallenges.List
                title="Tell Us How You Did It"
                rules=[|"What was your unique approach?", "Max 200 words", "Don't worry about grammar"|]
              />
            </TestworldChallenges.Accordian>
          </TestworldChallenges.Item>

          <TestworldChallenges.Item 
            title="Earn Tokens Selling SNARKs"
            rewardsMain="Earn up to 6,500 *Testnet Points"
            rewardsSub="Level up on the leaderboard, to get invited to our Genesis program."
          >
            <TestworldChallenges.Accordian>
              <TestworldChallenges.RewardsTable
                title="REWARDS"
                tableHead=[|"RESULT","MINA TOKENS"|]
                tableRow=[|"1st place", "6500", "2nd place", "5000", "3rd place", "4000", "Top 10", "3000", "Top 20", "2500", "Top 100", "1500", "Top 200", "1000" |]
              />
              <TestworldChallenges.SnarkRules title="RULES" />
              <TestworldChallenges.List
                title="Global Rules"
                rules=[|"Limit one wallet address per participant", "Limit one use of the faucet per participant", "If multiple participants are working together as a team, that team is limited to one wallet address, and one use of the faucet", "If multiple wallet addresses are used, only one address will be counted by our judges", "Node setup instructions are available in our documentation."|]
              />
              <TestworldChallenges.Link title="Docs: Getting Started"/>            
            </TestworldChallenges.Accordian>
          </TestworldChallenges.Item>

        </TestworldChallenges.Contanier>

        <TestworldChallenges.Contanier title1="TRANSACTIONS" title2="REWARDS">
          <TestworldChallenges.Item 
            title="Send Transactions"
            rewardsMain="Earn up to 6,500 *Testnet Points"
            rewardsSub="Level up on the leaderboard, to get invited to our Genesis program."
          >
            <TestworldChallenges.Accordian>
              <TestworldChallenges.RewardsTable
                title="REWARDS"
                tableHead=[|"RESULT","MINA TOKENS"|]
                tableRow=[|"1st place", "6500", "2nd place", "5000", "3rd place", "4000", "Top 10", "3000", "Top 20", "2500", "Top 100", "1500", "Top 200", "1000" |]
              />
              <TestworldChallenges.TransactionRules title="RULES" />
              <TestworldChallenges.List
                title="Global Rules"
                rules=[|"Limit one wallet address per participant", "Limit one use of the faucet per participant", "If multiple participants are working together as a team, that team is limited to one wallet address, and one use of the faucet", "If multiple wallet addresses are used, only one address will be counted by our judges", "Node setup instructions are available in our documentation."|]
              />
              <TestworldChallenges.Link title="Docs: Getting Started"/>
            </TestworldChallenges.Accordian>
          </TestworldChallenges.Item>

        </TestworldChallenges.Contanier>
      </TestworldChallenges.Header>
      <TestworldChallenges.Disclaimer 
      title="Testnet Points are designed solely to track contributions to the Testnet and are non-transferable. *Testnet Points have no cash or monetary value and are not redeemable for any cryptocurrency or digital assets. We may amend or eliminate *Testnet Points at any time. " 
      />

      <TestworldChallenges.Header title="Bonus Rewards">  
        <TestworldChallenges.Contanier title1="TESTWORLD RESULTS" title2="REWARDS">
          <TestworldChallenges.Item 
            title="Leaderboard Standings"
            rewardsMain="Earn up to 40,000 MINA Tokens"
            rewardsSub="Distributed after mainnet launch."
          >
          
            <TestworldChallenges.Accordian>
            <TestworldChallenges.ContainerSm>
                <p className=Theme.Type.paragraph>{React.string("Earn leaderboard points by participating in challenges where testnet points* are awarded to challenge winners. See the challenges above for more information.")}</p>
              </TestworldChallenges.ContainerSm>
              
              <TestworldChallenges.ContainerSm>
                <TestworldChallenges.Link title="Testnet Leaderboard"/>
              </TestworldChallenges.ContainerSm>

              <TestworldChallenges.BonusTable
                tableHead=[|"RESULT","MINA TOKENS"|]
                tableRow=[|"1st place", "40,000", "2nd place", "20,000", "3rd place", "10,000", "Top 10", "5,000", "Top 20", "2,000", "Top 50", "1,000"|]
              />
            </TestworldChallenges.Accordian>
          </TestworldChallenges.Item>
        </TestworldChallenges.Contanier>
    
      </TestworldChallenges.Header>
      <TestworldChallenges.Disclaimer
        title="Subject to Mina Foundation's approval"
      />
    </div>
      <div className=Theme.Type.errorMessage>
        {React.string("Error message")}
      </div>
      <div className=Theme.Type.pageSubhead>
        {React.string(
           "Page subhead / Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod temporus incididunt ut labore et dolore.",
         )}
      </div>
      <div className=Theme.Type.sectionSubhead>
        {React.string(
           "Section Subhead / Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod temporus incididunt ut labore et.",
         )}
      </div>
      <p className=Theme.Type.paragraph>
        {React.string(
           "Paragraph (Grotesk) / Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
         )}
      </p>
      <p className=Theme.Type.paragraphSmall>
        {React.string(
           "Paragraph Small (Grotesk) / Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
         )}
      </p>
      <p className=Theme.Type.paragraphMono>
        {React.string(
           "Paragraph (Mono) / Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmodorus temporus incididunt ut labore et dolore.",
         )}
      </p>
      <p className=Theme.Type.quote>
        {React.string(
           "Quote / Lorem ipsum dolor sit amet, consectetur amet adipiscing elit, sed do eiusmod tempor.",
         )}
      </p>
      <AlternatingSections
        backgroundImg=""
        sections={
          AlternatingSections.Section.SimpleRow([|
            {
              AlternatingSections.Section.SimpleRow.title: "Run a Node",
              description: "You don't have to have expensive hardware, wait days for the blockchain to sync, or use a ton of compute power to participate in consensus. Just follow clear, straightforward instructions and connect to the live peer-to-peer Mina network.",
              buttonCopy: "Get Started",
              buttonUrl: `Internal("/"),
              image: "/static/img/ProgrammableMoney.png",
            },
          |])
        }
      />
    </div>
    <ButtonBar
      kind=ButtonBar.HelpAndSupport
      backgroundImg="/static/img/ButtonBarBackground.jpg"
    />
    <ButtonBar
      kind=ButtonBar.CommunityLanding
      backgroundImg="/static/img/ButtonBarBackground.jpg"
    />
  </Page>;
};
