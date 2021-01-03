module Styles = {
  open Css;
  let page =
    style([display(`block), justifyContent(`center), overflowX(`hidden)]);
    
  let body =
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

  let flexCenter =
    style([
      display(`flex),
      flexDirection(`column),
      alignItems(`flexStart),
    ]);

  let container =
    style([
      Theme.Typeface.monumentGrotesk,
      display(`flex),
      flexDirection(`column),
      overflowX(`hidden),
      alignItems(`center),
      width(`percent(100.)),
      height(`percent(100.)),
      margin(`auto),
      /* padding2(~h=`rem(3.), ~v=`zero), */
      paddingBottom(`rem(3.)),
    ]);

  let background =
    style([
      width(`percent(100.)),
      height(`rem(180.)),
      backgroundColor(Theme.Colors.digitalBlack),
      backgroundSize(`cover),
      backgroundImage(`url("/static/img/backgrounds/LeadGen.jpg")),
    ]);

  let leaderboardBackground =
    style([
      backgroundImage(`url("/static/img/backgrounds/testworld_leaderboard.png")),
      backgroundSize(`cover),
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

  let leaderboardTextContainer =
    style([
      display(`flex),
      flexDirection(`column),
      alignItems(`center),
      justifyContent(`center),
      paddingTop(`rem(4.)),
      paddingBottom(`rem(2.)),
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
  let leaderboardLink =
    style([
      width(`percent(100.)),
      textDecoration(`none),
      height(`percent(100.)),
    ]);

    let disclaimer =
    merge([
      Theme.Type.disclaimer,
      style([paddingBottom(`rem(5.)), paddingTop(`rem(3.))]),
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
};

[@react.component]
let make = () => {
  <Page title="Testworld" showFooter=true darkTheme=true>
    <div className=Styles.page>
         <Hero.Dark
            title="ADVERSARIAL TESTNET"
            header={Some("Testworld")}
            copy={
              Some(
                {j|Push the boundaries of Mina’s testnet to help prepare for mainnet.|j},
              )
            }
            background={
              Theme.desktop: "/static/img/TestworldHeaderBackground.jpg",
              Theme.tablet: "/static/img/TestworldHeaderBackground.jpg",
              Theme.mobile: "/static/img/TestworldHeaderBackground.jpg",
            }
          >
          <div className=Styles.statusBadgeContainer>
            <span> {React.string("Testnet Status:")} </span>
            <span className=Styles.statusBadge>
              <StatusBadge service=`Network />
            </span>
          </div>
        </Hero.Dark>
    <ButtonBar
            kind=ButtonBar.TestworldHeader
            backgroundImg="/static/img/ButtonbarTestworldHeader.png"
          />
        <div className=Styles.container>
          
          <AnnouncementBar/>
          <RewardsPromo />
          <div className=Styles.body> 
        <TestworldChallenges.Header title="Testworld Challenges">  
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
                tableRow=[|"Top 20 Block Producers", "5% of MINA Treasury" |]
              />
              <TestworldChallenges.List
                title="RULES"
                rules=[|"MINA foundation will delegate 100% of its tokens post-mainnet to Testworld’s top block producers.", "Testworld’s top 20 block producing nodes will receive equal delegation.", "Each node will be delegated 5% of Foundation tokens.", "Selection criteria will be based on a combination of uptime & blocks produced."|]
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
                <Button href=`Scroll_to_top bgColor=Theme.Colors.mint dark=true>
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
                rules=[|"Find unconventional way(s) to optimize your earnings", "Tokens can only be earned via block production", "Look for approaches and strategies that could work on mainnet. If you’re confident your strategy would only work on testnet, it’s not worth trying. "|]
              />
              <TestworldChallenges.List
                title="Global Rules"
                rules=[|"Limit one wallet address per participant", "Limit one use of the faucet per participant", "If multiple participants are working together as a team, that team is limited to one wallet address, and one use of the faucet", "If multiple wallet addresses are used, only one address will be counted by our judges", "Node setup instructions are available in our documentation."|]
              />
              <TestworldChallenges.Link title="Docs: Getting Started"/>
              <TestworldChallenges.ContainerSm>
                <Button href=`Scroll_to_top bgColor=Theme.Colors.mint dark=true>
                    {React.string("TELL US YOUR APPROACH")}
                    <Icon kind=Icon.ArrowRightMedium />
                </Button>
              </TestworldChallenges.ContainerSm>
              <TestworldChallenges.List
                title="Tell Us How You Did It"
                rules=[|"What was your unique approach?", "Max 200 words", "Don’t worry about grammar"|]
              />
            </TestworldChallenges.Accordian>
          </TestworldChallenges.Item>
          <TestworldChallenges.Item 
            title="Produce Blocks"
            rewardsMain="Earn up to 6,500 Testnet Points*"
            rewardsSub="Level up on the leaderboard, to get invited to our Genesis program."
          >
            <TestworldChallenges.Accordian>
              <TestworldChallenges.RewardsTable
                title="REWARDS"
                tableHead=[|"RESULT","TESTNET POINTS*"|]
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
                rules=[|"Find unconventional way(s) to optimize your earnings", "Tokens can only be earned via SNARK production", "Look for approaches and strategies that could work on mainnet. If you’re confident your strategy would only work on testnet, it’s not worth trying. "|]
              />
              <TestworldChallenges.List
                title="Global Rules"
                rules=[|"Limit one wallet address per participant", "Limit one use of the faucet per participant", "If multiple participants are working together as a team, that team is limited to one wallet address, and one use of the faucet", "If multiple wallet addresses are used, only one address will be counted by our judges", "Node setup instructions are available in our documentation."|]
              />
              <TestworldChallenges.Link title="Docs: Getting Started"/>
              <TestworldChallenges.ContainerSm>
                <Button href=`Scroll_to_top bgColor=Theme.Colors.mint dark=true>
                    {React.string("TELL US YOUR APPROACH")}
                    <Icon kind=Icon.ArrowRightMedium />
                </Button>
              </TestworldChallenges.ContainerSm>
              <TestworldChallenges.List
                title="Tell Us How You Did It"
                rules=[|"What was your unique approach?", "Max 200 words", "Don’t worry about grammar"|]
              />
            </TestworldChallenges.Accordian>
          </TestworldChallenges.Item>

          <TestworldChallenges.Item 
            title="Produce & Sell SNARKs"
            rewardsMain="Earn up to 6,500 Testnet Points*"
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
            rewardsMain="Earn up to 6,500 Testnet Points*"
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

      <TestworldChallenges.Header title="Community Challenges">  
        <TestworldChallenges.Contanier title1="TESTWORLD RESULTS" title2="REWARDS">
          <TestworldChallenges.Item 
            title="Raise Awareness "
            rewardsMain="Earn up to 14,000 Testnet Points*"
            rewardsSub="Level up on the leaderboard, to get invited to our Genesis program."
            link=true
          >
             <Button
              bgColor=Theme.Colors.black
              href={`External(Constants.communityChallenges)}>
                  {React.string("View Details")}
                  <Icon kind=Icon.ChevronDown /> 
              </Button>
          </TestworldChallenges.Item>
        </TestworldChallenges.Contanier>
    
      </TestworldChallenges.Header>

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
                <TestworldChallenges.Link title="Docs: Getting Started"/>
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
        title="Testnet Points are designed solely to track contributions to the Testnet and are non-transferable. Testnet Points have no cash or monetary value and are not redeemable for any cryptocurrency or digital assets. We may amend or eliminate Testnet Points at any time. " 
      /></div>
      </div>
    </div>
    <div className=Styles.leaderboardBackground>
      <Wrapped>
        <div className=Styles.leaderboardTextContainer>
          <h2 className=Theme.Type.h2>
            {React.string("Testworld Leaderboard")}
          </h2>
          <Spacer height=1. />
          <p className=Theme.Type.paragraphMono>
            {React.string(
               "Mina rewards community members for contributing to Testnet with Testnet Points, making them stronger applicants for the Genesis Program.",
             )}
          </p>
          <Button
            bgColor=Theme.Colors.orange href={`Internal("/leaderboard")}>
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
             "*Testnet Points are designed solely to track contributions to the Testnet and are non-transferable. Testnet Points have no cash or monetary value and are not redeemable for any cryptocurrency or digital assets. We may amend or eliminate Testnet Points at any time.",
           )}
        </p>
      </Wrapped>
    </div>
    <ButtonBar
      kind=ButtonBar.TestworldFooter
      backgroundImg="/static/img/ButtonbarTestworld.png"
    />
  </Page>;
};
