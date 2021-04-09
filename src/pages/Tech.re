module Styles = {
  open Css;

  let section =
    style([
      width(`percent(100.)),
      maxWidth(`rem(71.)),
      margin2(~v=`auto, ~h=`auto),
      paddingTop(`rem(3.)),
      backgroundPosition(`rem(-6.5), `rem(-2.)),
      gridTemplateColumns([`em(14.), `auto]),
      selector("> aside", [gridColumnStart(1)]),
      selector("> :not(aside)", [gridColumnStart(2)]),
      selector("> img", [width(`percent(100.))]),
      media(Theme.MediaQuery.desktop, [paddingLeft(`rem(16.))]),
    ]);

  let sectionContainer = bg =>
    style([
      background(`url(bg)),
      padding2(~v=`rem(4.), ~h=`rem(2.)),
      backgroundSize(`cover),
      media(
        Theme.MediaQuery.desktop,
        [paddingTop(`rem(4.)), paddingBottom(`rem(10.))],
      ),
    ]);

  let sideNav = sticky =>
    style([
      display(`none),
      position(sticky ? `fixed : `absolute),
      top(sticky ? `rem(3.5) : `rem(66.)),
      marginLeft(`calc((`sub, `vw(50.), `rem(71. /. 2.)))),
      width(`rem(14.)),
      zIndex(Theme.StackingIndex.zNav),
      background(white),
      media(Theme.MediaQuery.desktop, [display(`block)]),
    ]);

  let projects =
    style([
      background(`url("/static/img/tech-projects-bg.jpg")),
      // For some reason `auto doesn't count as a Css.length so...
      unsafe("backgroundSize", "100% auto"),
      backgroundRepeat(`noRepeat),
      paddingTop(`rem(8.)),
    ]);

  let projectContainer =
    style([
      display(`flex),
      flexDirection(`column),
      alignItems(`center),
      selector("img", [width(`percent(100.)), marginBottom(`rem(2.))]),
      media(
        Theme.MediaQuery.desktop,
        [
          flexDirection(`row),
          selector("img", [width(`rem(23.)), marginRight(`rem(2.))]),
        ],
      ),
    ]);

  let possibilities =
    style([
      display(`grid),
      gridTemplateColumns([`fr(1.)]),
      gridGap(`rem(1.)),
      selector("img", [width(`percent(100.))]),
      media(
        Theme.MediaQuery.tablet,
        [gridTemplateColumns([`fr(1.), `fr(1.)])],
      ),
      media(
        Theme.MediaQuery.desktop,
        [gridTemplateColumns([`fr(1.), `fr(1.), `fr(1.)])],
      ),
    ]);

  let divider =
    style([
      maxWidth(`rem(71.)),
      margin2(~v=`zero, ~h=`auto),
      height(`px(1)),
      backgroundColor(Theme.Colors.digitalBlack),
    ]);

  let actionLink =
    merge([
      Theme.Type.link,
      style([display(`inlineFlex), alignItems(`center)]),
    ]);

  let usecaseLink =
    merge([Theme.Type.link, style([display(`flex), alignItems(`center)])]);

  let useCaseContainer = position => {
    style([
      switch (position) {
      | `Start => alignItems(`flexStart)
      | `Center => alignItems(`center)
      },
      display(`flex),
      justifyContent(`spaceBetween),
      width(`percent(100.)),
      marginBottom(`rem(2.)),
      flexDirection(`column),
      selector("> div > h4", [marginTop(`rem(4.))]),
      media(
        Theme.MediaQuery.notMobile,
        [selector("> div > h4", [marginTop(`zero)]), flexDirection(`row)],
      ),
      selector(
        "> img",
        [marginRight(`rem(1.)), width(`rem(23.)), height(`rem(23.))],
      ),
    ]);
  };

  let fadeOut =
    style([
      after([
        contentRule(""),
        position(`absolute),
        bottom(`zero),
        left(`zero),
        right(`zero),
        height(`rem(10.)),
        background(
          linearGradient(
            deg(0.),
            [
              (`percent(0.), white),
              (`percent(100.), rgba(255, 255, 255, 0.)),
            ],
          ),
        ),
      ]),
    ]);
};

module Section = {
  [@react.component]
  let make = (~title, ~subhead, ~slug, ~ref_, ~children) => {
    <section
      ref={ReactDOMRe.Ref.domRef(ref_)} className=Styles.section id=slug>
      <h2 className=Theme.Type.h2> {React.string(title)} </h2>
      <Spacer height=1.5 />
      <p className=Theme.Type.sectionSubhead> {React.string(subhead)} </p>
      <Spacer height=4. />
      children
      <Spacer height=6.5 />
    </section>;
  };
};

module HowMinaWorks = {
  [@react.component]
  let make = (~ref_) =>
    <div
      className={Styles.sectionContainer("/static/img/tech-gradient-1.jpg")}>
      <Spacer height=6.5 />
      <hr className=Styles.divider />
      <Section
        ref_
        title="How Mina Works"
        subhead={js|Mina is a layer one protocol designed to deliver on the original promise of blockchain — true decentralization, scale and security.|js}
        slug="how-mina-works">
        <img
          src="/static/img/how-mina-works-mirrors.jpg"
          alt="A series of mirrors reflecting each other ad infinitum."
        />
        <Spacer height=4. />
        <p className=Theme.Type.paragraph>
          <strong>
            {React.string(
               "In theory, blockchains are designed to be held accountable by its users.",
             )}
          </strong>
          {React.string(
             {js|
            When anyone can enforce the rules by validating an irrevocable public
            ledger — power remains in the hands of the many, not the few. This
            decentralized structure is what allows the network to conduct trustless
            transactions.
          |js},
           )}
        </p>
        <Spacer height=1.5 />
        <p className=Theme.Type.paragraph>
          <strong>
            {React.string(
               {js|But in practice, this hasn’t been the case.|js},
             )}
          </strong>
          {React.string(
             {js|
             With legacy blockchains like Bitcoin and Ethereum, when a new participant
             joins, they have to check every transaction since the beginning of the
             network to verify correctness — which amounts to hundreds of gigabytes of
             data. Most people can’t afford the computing power it takes to verify these
             heavy chains on their own and are forced  to trust increasingly powerful
             intermediaries. This means most folks can no longer connect peer-to-peer
             — causing decentralization to suffer, power dynamics to shift, and the
             network to become more vulnerable to censorship.
          |js},
           )}
        </p>
        <Spacer height=1.5 />
        <p className=Theme.Type.paragraph>
          <strong>
            {React.string(
               {js|
               Mina offers an elegant solution: replacing the blockchain with an
               easily verifiable, consistent-sized cryptographic proof.
             |js},
             )}
          </strong>
          {React.string(
             {js|
             Mina dramatically reduces the amount of data each user needs to download.
             Instead of verifying the entire chain from the beginning of time,
             participants fully verify the network and transactions using recursive
             zero knowledge proofs (or zk-SNARKs). Nodes can then store the small proof, as opposed to the entire chain.
             And because it’s a consistent size, Mina stays accessible — even
             as it scales to many users and accumulates years of transaction data.
          |js},
           )}
        </p>
        <Spacer height=4. />
        <img
          src="/static/img/mina-cubes.gif"
          alt="A series of mirrors reflecting each other ad infinitum."
        />
        <Spacer height=4. />
        <p className=Theme.Type.paragraph>
          <strong> {React.string("But how do zk-SNARKs work?")} </strong>
          {React.string(
             {js|
            They capture the state of the entire blockchain as a lightweight snapshot
            and send that around — instead of the chain itself. It’s like sending your
            friend a postcard of an elephant, instead of a massive live animal. When
            the next block in the network is created, it takes a snapshot of itself
            — with the snapshot of the previous state of the blockchain as the background.
            That new snapshot will in turn be used as the backdrop for the next block,
            and so on and so on. Rather amazingly, while it can contain proof of an
            infinite amount of information, the snapshot always remains the same size.
          |js},
           )}
        </p>
        <Spacer height=1.5 />
        <p className=Theme.Type.paragraph>
          <strong>
            {React.string(
               {js|
               Coming full circle, the world’s lightest blockchain empowers inclusive consensus.
             |js},
             )}
          </strong>
          {React.string(
             {js|
             Our modified Ouroboros proof-of-stake protocol maximizes inclusivity in
             consensus. On Mina, all participants act as full nodes and anyone can take
             part in consensus, secure the blockchain and hold Mina accountable.
          |js},
           )}
        </p>
        <Spacer height=1.5 />
        <p className=Theme.Type.paragraph>
          <strong>
            {React.string(
               {js|
               And that’s how Mina will deliver true decentralization, scale and security.
             |js},
             )}
          </strong>
        </p>
      </Section>
    </div>;
};

module Projects = {
  module ProjectCopy = {
    [@react.component]
    let make = (~title, ~description, ~url) =>
      <div>
        <h4 className=Theme.Type.h4> {React.string(title)} </h4>
        <Spacer height=0.5 />
        <p className=Theme.Type.paragraph> {React.string(description)} </p>
        <Spacer height=0.5 />
        <a href=url className=Styles.actionLink>
          <span className=Theme.Type.link>
            {React.string("See it in Action")}
          </span>
          <Icon size=1.5 kind=Icon.ExternalLink />
        </a>
      </div>;
  };

  module Possibility = {
    [@react.component]
    let make = (~title, ~description, ~image) =>
      <div>
        <img src=image />
        <Spacer height=1. />
        title
        <Spacer height=0.5 />
        description
      </div>;
  };

  module UseCaseRow = {
    type position = [ | `Start | `Center];
    [@react.component]
    let make =
        (
          ~title,
          ~description,
          ~image,
          ~ctaCopy="Learn More",
          ~ctaLink,
          ~position=`Center,
        ) =>
      <div className={Styles.useCaseContainer(position)}>
        <img src=image />
        <div>
          title
          <Spacer height=0.5 />
          description
          <Spacer height=0.5 />
          <a href=ctaLink className=Styles.usecaseLink>
            {React.string(ctaCopy)}
            <Icon kind=Icon.ExternalLink />
          </a>
        </div>
      </div>;
  };

  [@react.component]
  let make = (~ref_) =>
    <div
      className={Css.merge([
        Styles.sectionContainer("/static/img/tech-projects-bg.jpg"),
        Styles.fadeOut,
      ])}>
      <Spacer height=5. />
      <Section
        ref_
        title="Projects & Possibilities"
        subhead={js|Mina is a powerful tool. Here's what we're building with it.|js}
        slug="projects">
        <hr className=Styles.divider />
        <Spacer height=1. />
        <h3 className=Theme.Type.h3> {React.string("Use Cases")} </h3>
        <Spacer height=3. />
        <p className=Theme.Type.subheadMono>
          {React.string(
             {js|Mina is focusing on three use cases that will help us build a private gateway between the real world and crypto — and the infrastructure for the secure, democratic future we all deserve.|js},
           )}
        </p>
        <Spacer height=3. />
        <div>
          <UseCaseRow
            title={
              <h4 className=Theme.Type.h4>
                {React.string(
                   "End-to-End Data Privacy, from Online to On-chain",
                 )}
              </h4>
            }
            description=
              {<>
                 <p className=Theme.Type.paragraph>
                   {React.string(
                      {js|Users can access critical on-chain services without sharing their personal data. Instead, they use Mina to access their online data and to prove that they meet the requirements of service providers. No need for a trusted enclave that can be compromised. No data vulnerabilities, end-to-end. For example, today Mina’s Snapps can connect to a credit score provider to prove that your credit score is above a certain threshold. Soon, you’ll be able to prove so much more from any website.|js},
                    )}
                 </p>
                 <i className=Theme.Type.paragraph>
                   {React.string({js|Status: Demo In Use.|js})}
                 </i>
               </>}
            image="/static/img/EndToEndPrivacy.jpg"
            position=`Start
            ctaCopy="Sign up to see this in action"
            ctaLink=Constants.minaOnChainUseCaseDemo
          />
          <UseCaseRow
            title={
              <h4 className=Theme.Type.h4>
                {React.string("Permissionless Web Oracles")}
              </h4>
            }
            description=
              {<>
                 <p className=Theme.Type.paragraph>
                   {React.string(
                      {js|With Snapps, developers can leverage private, verified, real world data from any website to build decentralized apps. They can input any information that is publicly available on the web (without needing that website’s permission). And they can access, use and protect sensitive data by only sharing the relevant proofs. No need for trusted oracles or custom website integrations.|js},
                    )}
                 </p>
                 <i className=Theme.Type.paragraph>
                   {React.string({js|Status: In Development.|js})}
                 </i>
               </>}
            image="/static/img/PermisionlessWebOracles.jpg"
            ctaLink="blog/building-a-private-gateway-between-the-real-world-and-crypto-three-use-cases"
          />
          <UseCaseRow
            title={
              <h4 className=Theme.Type.h4>
                {React.string("One Private Internet Login")}
              </h4>
            }
            description=
              {<>
                 <p className=Theme.Type.paragraph>
                   {React.string(
                      {js|Users can access any internet website or service privately — without creating an account and handing over their personal data. Instead, they login securely with Mina. No centralized service provider can block them. And developers across chains can integrate this private, secure option into their services. |js},
                    )}
                   <i className=Theme.Type.paragraph>
                     {React.string({js|Status: In Development.|js})}
                   </i>
                 </p>
               </>}
            image="/static/img/PrivateLogin.jpg"
            ctaLink="blog/building-a-private-gateway-between-the-real-world-and-crypto-three-use-cases"
          />
        </div>
        <Spacer height=3. />
        <hr className=Styles.divider />
        <Spacer height=1. />
        <h3 className=Theme.Type.h3>
          {React.string("Explore the Possiblities")}
        </h3>
        <Spacer height=3. />
        <p className=Theme.Type.subheadMono>
          {React.string(
             "Mina's decentralized, democratic design opens up a world of good.",
           )}
        </p>
        <Spacer height=3. />
        <div className=Styles.possibilities>
          <Possibility
            title={
              <h4 className=Theme.Type.h4>
                {React.string("Build Snapps")}
                <Footnote refNumber="3" link="/disclaimers" />
                {React.string(" Privacy-Enabled apps")}
              </h4>
            }
            description={
              <p className=Theme.Type.paragraph>
                {React.string(
                   "Leverage Mina to develop decentralized apps that use zk-SNARKs to ensure privacy, without exposing users' data to a public blockchain.",
                 )}
              </p>
            }
            image="/static/img/tech-build-snapps.svg"
          />
          <Possibility
            title={
              <h4 className=Theme.Type.h4>
                {React.string("Power Enterprise Interoperability")}
              </h4>
            }
            description={
              <p className=Theme.Type.paragraph>
                {React.string(
                   "Use Mina to combine the cost-efficiency and privacy of a private chain with the interoperability of a public chain.",
                 )}
              </p>
            }
            image="/static/img/tech-power-interop.svg"
          />
          <Possibility
            title={
              <h4 className=Theme.Type.h4>
                {React.string("Minimize Transaction Fees")}
              </h4>
            }
            description={
              <p className=Theme.Type.paragraph>
                {React.string(
                   "Power trustless e-commerce and global peer-to-peer transactions without using centralized intermediaries, or paying costly transaction fees.",
                 )}
              </p>
            }
            image="/static/img/tech-txn-fees.svg"
          />
          <Possibility
            title={
              <h4 className=Theme.Type.h4>
                {React.string("Power Secure & Fair Financial Services")}
              </h4>
            }
            description={
              <p className=Theme.Type.paragraph>
                {React.string(
                   "Ensure lenders only use fair criteria to make decisions and securely verify relevant information without accessing private user data.",
                 )}
              </p>
            }
            image="/static/img/tech-power-fair.svg"
          />
          <Possibility
            title={
              <h4 className=Theme.Type.h4>
                {React.string("Enable private & auditable elections ")}
              </h4>
            }
            description={
              <p className=Theme.Type.paragraph>
                {React.string(
                   "Guarantee fully verifiable and auditable elections, while keeping the process private and  protecting individuals' voting information.",
                 )}
              </p>
            }
            image="/static/img/tech-audit.svg"
          />
          <Possibility
            title={
              <h4 className=Theme.Type.h4>
                {React.string("Access Money from Anywhere in the world")}
              </h4>
            }
            description={
              <p className=Theme.Type.paragraph>
                {React.string("With a 22kb")}
                <Footnote
                  refNumber="1"
                  link="blog/22kb-sized-blockchain-a-technical-reference"
                />
                {React.string(
                   " Mina chain, access peer-to-peer stablecoins and tokens via smartphone and bring hard-earned money anywhere you go.",
                 )}
              </p>
            }
            image="/static/img/tech-access.svg"
          />
        </div>
      </Section>
    </div>;
};

module Incentives = {
  module Incentive = {
    [@react.component]
    let make = (~title, ~description, ~image, ~url) =>
      <div className=Styles.projectContainer>
        <img src=image />
        <div>
          <h4 className=Theme.Type.h4> {React.string(title)} </h4>
          <Spacer height=0.5 />
          <p className=Theme.Type.paragraph> {React.string(description)} </p>
          <Spacer height=0.5 />
          <Next.Link href=url>
            <a className=Styles.actionLink>
              <span className=Theme.Type.link>
                {React.string("Run a Node")}
              </span>
              <Spacer width=0.5 />
              <Icon size=1.5 kind=Icon.ArrowRightMedium />
            </a>
          </Next.Link>
        </div>
      </div>;
  };

  [@react.component]
  let make = (~ref_) =>
    <div className={Styles.sectionContainer("")}>
      <Spacer height=1.5 />
      <hr className=Styles.divider />
      <Section
        ref_
        title="Incentive Structure"
        subhead="From its protocol architecture and roles framework to its incentive structure and monetary policy, Mina is designed to maximize network scalability and security."
        slug="incentives">
        <Button
          width={`rem(15.25)}
          href={`Internal("/static/pdf/economicsWhitepaper.pdf")}>
          {React.string("Economics Whitepaper")}
          <Icon kind=Icon.ArrowRightSmall />
        </Button>
        <Spacer height=4. />
        <hr className=Styles.divider />
        <Spacer height=2. />
        <h3 className=Theme.Type.h3> {React.string("Ways to Join Mina")} </h3>
        <Spacer height=2. />
        <p className=Theme.Type.sectionSubhead>
          {React.string(
             "Mina is breaking down barriers to participation and unleashing a host of exciting new opportunities.",
           )}
        </p>
        <Spacer height=3. />
        <Incentive
          title="As a Block Producer"
          description="Block producers are akin to miners or stakers in other protocols. By staking Mina, they can be selected to produce a block and earn block rewards in the form of coinbase, transaction fees and network fees. Block producers can decide to also be SNARK producers."
          image="/static/img/tech-block-producer.png"
          url="/docs"
        />
        <Spacer height=3. />
        <Incentive
          title="As a Snark Producer"
          description="The second type of consensus node operator on Mina, snark producers help compress data in the network by generating SNARK proofs of transactions. They then sell those proofs to block producers in return for a portion of the block rewards."
          image="/static/img/tech-snark-producer.png"
          url="/docs"
        />
        <Spacer height=3. />
        <Incentive
          title="As a Professional Block Producer"
          description="Because staking requires nodes to be online, some may choose to delegate their Mina to staking pools. These groups run staking services in exchange for a fee, which is automatically deducted when the delegator gets selected to be a block producer."
          image="/static/img/tech-pro-delegator.png"
          url="/docs"
        />
      </Section>
    </div>;
};

[@react.component]
let make = () => {
  let (howMinaWorksRef, howMinaWorksVisible) =
    Hooks.useOnScreen(
      ~options=
        {ReactExt.IntersectionObserver.rootMargin: "0px 0px -150px 0px"}
        ->Some,
      (),
    );
  let (projectPossibilitiesRef, projectPossibilitiesVisible) =
    Hooks.useOnScreen(
      ~options=
        {ReactExt.IntersectionObserver.rootMargin: "0% 0% -90% 0%"}->Some,
      (),
    );
  let (incentiveRef, incentiveVisible) =
    Hooks.useOnScreen(
      ~options=
        {ReactExt.IntersectionObserver.rootMargin: "0% 0% -90% 0%"}->Some,
      (),
    );

  let (whereHeadedRef, whereHeadedVisible) =
    Hooks.useOnScreen(
      ~options=
        {ReactExt.IntersectionObserver.rootMargin: "0% 0% -90% 0%"}->Some,
      (),
    );

  let (knowledgebaseRef, knowledgebaseVisible) =
    Hooks.useOnScreen(
      ~options=
        {ReactExt.IntersectionObserver.rootMargin: "0% 0% -90% 0%"}->Some,
      (),
    );
  let (currentItem, setCurrentItem) = React.useState(_ => "");

  let navItems = [|
    ("How Mina Works", "#how-mina-works"),
    ("Projects & Possibilities", "#projects"),
    ("Incentive Structure", "#incentives"),
    ("Where We're Headed", "#roadmap"),
    ("Knowledge Base", "#knowledge"),
  |];

  React.useEffect5(
    () => {
      howMinaWorksVisible ? setCurrentItem(_ => "How Mina Works") : ();

      projectPossibilitiesVisible
        ? setCurrentItem(_ => "Projects & Possibilities") : ();

      incentiveVisible ? setCurrentItem(_ => "Incentive Structure") : ();

      whereHeadedVisible ? setCurrentItem(_ => "Where We're Headed") : ();

      knowledgebaseVisible ? setCurrentItem(_ => "Knowledge Base") : ();

      None;
    },
    (
      howMinaWorksVisible,
      projectPossibilitiesVisible,
      incentiveVisible,
      whereHeadedVisible,
      knowledgebaseVisible,
    ),
  );

  let renderSideNav = () => {
    <Context.SideNavCurrentItemContext value=currentItem>
      <TechNav.SideNav>
        {navItems
         |> Array.map(item => {
              let (title, slug) = item;
              <span key=title> <SideNav.Item title slug /> </span>;
            })
         |> React.array}
      </TechNav.SideNav>
    </Context.SideNavCurrentItemContext>;
  };

  <Page title="Mina Cryptocurrency Protocol" footerColor=Theme.Colors.orange>
    <div className=Nav.Styles.spacer />
    <Hero
      background={
        Theme.desktop: "/static/img/backgrounds/tech-hero-desktop.jpg",
        Theme.tablet: "/static/img/backgrounds/tech-hero-tablet.jpg",
        Theme.mobile: "/static/img/backgrounds/tech-hero-mobile.jpg",
      }
      title="Tech"
      header={Some("An Elegant Solution")}
      copy={
        Some(
          "Rather than apply brute computing force, Mina uses advanced cryptography and recursive zk-SNARKs to deliver true decentralization at scale.",
        )
      }
    />
    {renderSideNav()}
    <TechNav.Dropdown />
    <HowMinaWorks ref_=howMinaWorksRef />
    <Projects ref_=projectPossibilitiesRef />
    <Incentives ref_=incentiveRef />
    <div
      className={Styles.sectionContainer("/static/img/tech-projects-bg.jpg")}>
      <Spacer height=1.5 />
      <Section
        ref_=whereHeadedRef
        title="Mina Milestones and the Road Ahead"
        subhead={js|
          We’re proud of what we’ve accomplished with our community so far — and
          look forward to tackling challenges and building more with a whole new
          generation of participants.
        |js}
        slug="roadmap">
        <picture>
          <source
            media=Theme.MediaQuery.mobile
            srcSet="/static/img/tech-roadmap-mobile.svg"
          />
          <source
            media=Theme.MediaQuery.notMobile
            srcSet="/static/img/tech-roadmap-desktop.svg"
          />
          <img src="/static/img/tech-roadmap-desktop.svg" width="100%" />
        </picture>
      </Section>
      <Spacer height=7. />
    </div>
    <FeaturedSingleRow
      row={
        rowType: FeaturedSingleRow.Row.ImageRightCopyLeft,
        title: "Get Started",
        description: {js|
          We make it as simple as possible to participate in Mina. With clear documentation, a supportive community and a chain that syncs quickly, we’ll get you up and running in record time.
        |js},
        textColor: `currentColor,
        copySize: `Small,
        image: "/static/img/tech-skateboard.jpg",
        background: Image("/static/img/MinaSpectrumPrimary3.jpg"),
        link:
          FeaturedSingleRow.Row.Button({
            buttonColor: Theme.Colors.orange,
            buttonTextColor: Css.white,
            href: `Internal("/docs/getting-started"),
            buttonText: "Run a Node",
            dark: false,
          }),
        contentBackground: Color(Css.white),
      }
    />
    <div
      className={Styles.sectionContainer(
        "/static/img/backgrounds/TechKnowledgeBaseBackground.jpg",
      )}>
      <Wrapped>
        <section
          ref={ReactDOMRe.Ref.domRef(knowledgebaseRef)}
          className=Styles.section
          id="knowledge">
          <KnowledgeBase />
        </section>
      </Wrapped>
    </div>
    <FeaturedSingleRow
      row={
        rowType: FeaturedSingleRow.Row.ImageLeftCopyRight,
        title: "Work on the Core Protocol",
        description: {js|
          Interested in joining a team of passionate engineers and putting your
          coding skills to work at the protocol level?
        |js},
        textColor: `currentColor,
        copySize: `Small,
        image: "/static/img/tech-touch.jpg",
        background: Image("/static/img/MinaSpectrumPrimarySilver.jpg"),
        link:
          FeaturedSingleRow.Row.Button({
            buttonColor: Theme.Colors.orange,
            buttonTextColor: Css.white,
            buttonText: "Work with Mina",
            dark: false,
            href: `Internal("/work-with-mina"),
          }),
        contentBackground: Color(Css.white),
      }
    />
  </Page>;
};
