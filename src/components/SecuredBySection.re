module Styles = {
  open Css;
  let backgroundImage =
    style([
      backgroundSize(`cover),
      backgroundImage(url("/static/img/SecuredBySmall.jpg")),
      media(
        Theme.MediaQuery.tablet,
        [backgroundImage(url("/static/img/SecuredByMedium.jpg"))],
      ),
      media(
        Theme.MediaQuery.desktop,
        [backgroundImage(url("/static/img/SecuredByLarge.jpg"))],
      ),
    ]);
  let grid =
    style([
      display(`grid),
      padding2(~v=rem(4.), ~h=`rem(0.)),
      gridTemplateColumns([`percent(100.)]),
      gridTemplateRows([`rem(33.), `rem(27.), `rem(54.)]),
      gridRowGap(`rem(4.)),
      media(
        Theme.MediaQuery.tablet,
        [
          gridTemplateColumns([`rem(43.)]),
          gridTemplateRows([`rem(34.), `rem(18.06), `rem(27.)]),
          gridRowGap(`rem(4.)),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [
          gridTemplateColumns([`rem(31.5), `rem(29.)]),
          gridTemplateRows([`rem(31.5), `rem(27.)]),
          gridColumnGap(`rem(6.8)),
          gridRowGap(`rem(6.)),
          backgroundSize(`cover),
        ],
      ),
    ]);
  let gridItem1 = style([unsafe("grid-area", "1 / 1 / 2 / 2")]);
  let gridItem2 = style([unsafe("grid-area", "2 / 1 / 3 / 2")]);
  let gridItem3 =
    style([
      backgroundColor(Theme.Colors.digitalBlack),
      height(`rem(62.)),
      padding2(~v=`rem(2.), ~h=`rem(2.)),
      unsafe("grid-area", "3"),
      media(
        Theme.MediaQuery.tablet,
        [
          display(`flex),
          flexDirection(`row),
          unsafe("grid-area", "3 / 1 / 3 / 3"),
          marginTop(`rem(4.)),
          height(`rem(22.)),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [
          unsafe("grid-area", "1 / 2 / 3 / 3"),
          flexDirection(`column),
          marginTop(`rem(0.)),
          padding2(~v=`rem(4.), ~h=`rem(3.5)),
          height(`rem(73.4)),
        ],
      ),
    ]);
  // This is the third dark background grid item
  let textColumn =
    style([
      media(
        Theme.MediaQuery.tablet,
        [display(`flex), flexDirection(`column), height(`rem(73.4))],
      ),
      media(
        Theme.MediaQuery.desktop,
        [marginTop(`rem(2.)), marginLeft(`zero)],
      ),
    ]);
  let flexRow =
    style([
      display(`flex),
      width(`percent(100.)),
      flexDirection(`row),
      justifyContent(`spaceBetween),
      media(Theme.MediaQuery.tablet, [width(`rem(30.))]),
    ]);
  let imageColumn =
    style([
      width(`rem(10.)),
      media(Theme.MediaQuery.tablet, [width(`rem(13.))]),
    ]);
  let logoGrid =
    style([
      display(`grid),
      gridRowGap(`rem(1.)),
      gridColumnGap(`rem(1.)),
      gridTemplateRows([`rem(5.), `rem(5.)]),
      gridTemplateColumns([`rem(10.), `rem(10.)]),
      media(
        Theme.MediaQuery.tablet,
        [
          gridTemplateRows([`rem(5.)]),
          gridTemplateColumns([
            `rem(10.),
            `rem(10.),
            `rem(10.),
            `rem(10.),
          ]),
          marginBottom(`rem(4.)),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [
          gridTemplateRows([`rem(8.5), `rem(8.5)]),
          gridTemplateColumns([`rem(17.), `rem(17.)]),
          marginBottom(`zero),
        ],
      ),
    ]);
  let logo =
    style([
      height(`rem(5.)),
      media(Theme.MediaQuery.desktop, [height(`rem(8.5))]),
    ]);
  let h2 =
    merge([
      Theme.Type.h2,
      style([lineHeight(`rem(3.0)), fontSize(`rem(2.5))]),
    ]);
  let h3White =
    merge([
      Theme.Type.h3,
      style([
        color(white),
        marginTop(`rem(1.5)),
        marginBottom(`rem(1.)),
      ]),
    ]);
  let labelWhite =
    merge([Theme.Type.sectionSubhead, style([color(white)])]);
  let dotsImage =
    style([
      media(
        Theme.MediaQuery.tablet,
        [marginRight(`rem(3.)), height(`rem(15.))],
      ),
      media(
        Theme.MediaQuery.desktop,
        [marginRight(`zero), marginBottom(`zero), height(`rem(99.))],
      ),
    ]);
  let button = style([media(Theme.MediaQuery.tablet, [])]);
};

[@react.component]
let make = () => {
  <div className=Styles.backgroundImage>
    <Wrapped>
      <div className=Styles.grid>
        <div className=Styles.gridItem1>
          <Rule />
          <Spacer height=2. />
          <h2 className=Styles.h2>
            {React.string("Secured by Participants")}
          </h2>
          <Spacer height=1. />
          <p className=Theme.Type.sectionSubhead>
            {React.string(
               "The Mina network is secured by an uncapped number of block producers via proof-of-stake consensus. A uniquely decentralized blockchain, Mina gets even more secure and resilient as it grows.",
             )}
          </p>
          <Spacer height=3. />
          <div className=Styles.flexRow>
            <span className=Styles.imageColumn>
              <img src="/static/img/AboutBlockProducers.svg" />
              <h3 className=Theme.Type.h3> {React.string("100s")} </h3>
              <p className=Theme.Type.label>
                {React.string("Block Producers")}
              </p>
            </span>
            <span className=Styles.imageColumn>
              <img src="/static/img/AboutSnarkProducers.svg" />
              <h3 className=Theme.Type.h3> {React.string("100s")} </h3>
              <p className=Theme.Type.label>
                {React.string("Snark Producers")}
              </p>
            </span>
          </div>
        </div>
        <Spacer height=4. />
        <div className=Styles.gridItem2>
          <Rule />
          <Spacer height=2. />
          <h2 className=Styles.h2>
            {React.string("Featured Block Producers")}
          </h2>
          <Spacer height=1. />
          <p className=Theme.Type.sectionSubhead>
            {React.string(
               "Delegating is an alternative to staking Mina directly, with the benefit of not having to maintain a node that is always connected to the network. Here are some of the professional block producers offering staking services on Mina.",
             )}
          </p>
          <Spacer height=2. />
          <div className=Styles.logoGrid>
            <img className=Styles.logo src="/static/img/BisonTrailsLogo.png" />
            <img
              className=Styles.logo
              src="/static/img/FigmentNetworksLogo.png"
            />
            <img className=Styles.logo src="/static/img/NonceLogo.png" />
            <img className=Styles.logo src="/static/img/SnarkPoolLogo.png" />
          </div>
        </div>
        <div className=Styles.gridItem3>
          <img
            className=Styles.dotsImage
            src="/static/img/SecuredByDots.svg"
          />
          <span className=Styles.textColumn>
            <Rule color=Theme.Colors.white />
            <h3 className=Styles.h3White>
              {React.string("You Can Run a Node & Secure the Network")}
            </h3>
            <p className=Styles.labelWhite>
              {React.string(
                 "With Mina's uniquely light blockchain, you don't have to have expensive hardware, or wait days for the blockchain to sync, or use a ton of computing power to stake and participate in consensus.",
               )}
            </p>
            <Spacer height=2. />
            <span className=Styles.button>
              <Button
                bgColor=Theme.Colors.orange
                dark=true
                href={`Internal("/docs")}>
                {React.string("Get Started")}
                <Icon kind=Icon.ArrowRightSmall />
              </Button>
            </span>
          </span>
        </div>
      </div>
    </Wrapped>
  </div>;
};
