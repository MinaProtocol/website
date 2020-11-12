open Css;
module Styles = {
  let rowBackgroundImage =
    style([
      height(`percent(100.)),
      width(`percent(100.)),
      important(backgroundSize(`cover)),
      backgroundImage(`url("/static/img/BackgroundGlowCluster01.jpg")),
    ]);

  let container =
    style([
      display(`flex),
      flexDirection(`column),
      paddingLeft(`rem(1.5)),
      paddingRight(`rem(1.5)),
      paddingBottom(`rem(4.)),
      media(Theme.MediaQuery.tablet, [paddingLeft(`rem(3.0))]),
      media(
        Theme.MediaQuery.desktop,
        [
          position(`relative),
          flexDirection(`row),
          maxWidth(`rem(96.)),
          padding2(~h=`rem(9.5), ~v=`rem(8.)),
        ],
      ),
    ]);

  /** Can reuse and extract into a reusable component in the future */
  let column =
    style([
      display(`flex),
      flexDirection(`column),
      justifyContent(`flexStart),
      width(`percent(100.)),
      media(Theme.MediaQuery.tablet, [width(`rem(30.))]),
      media(Theme.MediaQuery.desktop, [width(`rem(35.))]),
    ]);

  /* First and second rows  */
  let firstColumn =
    merge([
      column,
      style([
        media(Theme.MediaQuery.tablet, [marginRight(`rem(0.))]),
        media(Theme.MediaQuery.desktop, [marginRight(`rem(7.))]),
      ]),
    ]);
  let secondColumn =
    merge([
      column,
      style([
        marginLeft(`zero),
        media(Theme.MediaQuery.tablet, [marginLeft(`rem(23.))]),
        media(Theme.MediaQuery.desktop, [marginLeft(`rem(35.))]),
      ]),
    ]);

  let header =
    merge([
      Theme.Type.h1,
      style([media(Theme.MediaQuery.desktop, [width(`rem(25.2))])]),
    ]);
  let subhead =
    merge([Theme.Type.sectionSubhead, style([letterSpacing(`px(-1))])]);
  let heroRowImage =
    style([
      width(`percent(100.)),
      media(Theme.MediaQuery.tablet, [width(`percent(35.))]),
      media(
        Theme.MediaQuery.desktop,
        [marginTop(`zero), height(`rem(38.5)), width(`rem(38.5))],
      ),
    ]);
  let firstImage =
    merge([
      heroRowImage,
      style([
        media(
          Theme.MediaQuery.tablet,
          [position(`absolute), right(`rem(-9.5))],
        ),
        media(
          Theme.MediaQuery.desktop,
          [position(`absolute), right(`rem(0.))],
        ),
      ]),
    ]);
  let secondImage =
    merge([
      heroRowImage,
      style([
        backgroundImage(`url("/static/img/triangle_mobile.jpg")),
        media(
          Theme.MediaQuery.tablet,
          [
            position(`absolute),
            left(`zero),
            backgroundImage(`url("/static/img/triangle_tablet.jpg")),
          ],
        ),
        media(
          Theme.MediaQuery.desktop,
          [backgroundImage(`url("/static/img/triangle_desktop.jpg"))],
        ),
      ]),
    ]);
  let imageContainer = style([position(`relative)]);

  let copy = Theme.Type.paragraph;
  let rule =
    style([
      width(`percent(100.)),
      color(Theme.Colors.digitalBlack),
      border(`px(1), `solid, black),
      marginTop(`rem(4.)),
      media(Theme.MediaQuery.tablet, [marginTop(`zero)]),
    ]);
  let orange =
    merge([
      copy,
      style([
        display(`inlineBlock),
        textDecoration(`none),
        color(Theme.Colors.orange),
      ]),
    ]);

  let specialSpacer =
    style([
      height(`rem(0.)),
      media(Theme.MediaQuery.tablet, [height(`rem(4.))]),
    ]);
  let largestSpacer =
    style([
      height(`rem(0.)),
      media(Theme.MediaQuery.tablet, [height(`rem(8.))]),
    ]);
};

[@react.component]
let make = () => {
  <div className=Styles.rowBackgroundImage>
    <div className=Styles.specialSpacer />
    <div className=Styles.container>
      <div className=Styles.firstColumn>
        <hr className=Styles.rule />
        <Spacer height=1.5 />
        <h2 className=Styles.header>
          {React.string("It's Time to Own Our Future")}
        </h2>
        <Spacer height=1.5 />
        <p className=Styles.subhead>
          {React.string(
             "Living in today's world requires giving up a lot of control.",
           )}
        </p>
        <Spacer height=1. />
        <p className=Styles.copy>
          {React.string(
             "Every day, we give up control of intimate data to large tech companies to use online services. We give up control of our finances to banks and unaccountable credit bureaus. We give up control of our elections to voting system companies who run opaque and unauditable elections. ",
           )}
        </p>
        <Spacer height=1. />
        <p className=Styles.copy>
          {React.string(
             "Even when we try to escape this power imbalance and participate in blockchains, most of us give up control and trust to third parties to verify transactions. Why? Because running a full node requires expensive hardware, unsustainable amounts of electricity and tons of time to sync increasingly heavier and heavier chains.",
           )}
        </p>
        <Spacer height=1. />
        <p className=Styles.copy>
          <strong>
            {React.string("But it doesn't have to be this way. ")}
          </strong>
        </p>
      </div>
      <Spacer height=3.0 />
      <img
        className=Styles.firstImage
        src="/static/img/AboutHeroRow1Image.jpg"
      />
    </div>
    <div className=Styles.container>
      <div className=Styles.secondColumn>
        <p className=Styles.subhead>
          {React.string("That's why we created Mina.")}
        </p>
        <p className=Styles.copy>
          {React.string(
             "In June of 2017, O(1) Labs kicked off an ambitious
               new open source project to design a layer one protocol
               that could deliver on the original promise of blockchain
               - true decentralization, scale and security.
               Rather than apply brute computing force, Mina offers
               an elegant solution using advanced cryptography
               and recursive zk-SNARKs. ",
           )}
        </p>
        <Spacer height=1. />
        <p className=Styles.copy>
          {React.string(
             "Over the past three years,
               our team together with our incredible
               community have launched and learned through several
               testnet phases. And now, at long last, we are proud
               to introduce Mina to the wider world. Here, developers
               can build ",
           )}
          <Next.Link href="/docs">
            <span className=Styles.orange>
              {React.string("powerful applications ")}
            </span>
          </Next.Link>
          {React.string(
             " like Snapps (SNARK-powered apps)
               to offer financial services without compromising data privacy
               and programmable money that anyone can access trustlessly from their phones.
               And that's just the beginning.",
           )}
        </p>
        <Spacer height=1. />
        <p className=Styles.copy>
          {React.string(
             "While there will still be challenges to come, the world's lightest, most accessible blockchain is ready to be powered by a whole new generation of participants.",
           )}
        </p>
        <Spacer height=1. />
        <p className=Styles.copy>
          <strong>
            {React.string(
               "Here's to a more efficient, elegant and fair future - for all of us.",
             )}
          </strong>
        </p>
        <Spacer height=4. />
        <img
          className=Styles.secondImage
          src="/static/img/triangle_desktop.jpg"
        />
        <div className=Styles.largestSpacer />
      </div>
    </div>
  </div>;
};
