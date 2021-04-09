module Styles = {
  open Css;
  let header = merge([Theme.Type.h1, style([marginBottom(`rem(0.5))])]);

  let sectionSubhead =
    merge([
      Theme.Type.sectionSubhead,
      style([
        fontSize(`px(19)),
        lineHeight(`rem(1.75)),
        letterSpacing(`pxFloat(-0.4)),
        media(Theme.MediaQuery.desktop, [maxWidth(`rem(41.))]),
      ]),
    ]);

  let grid =
    style([
      display(`grid),
      paddingTop(`rem(2.)),
      gridTemplateColumns([`rem(11.5), `rem(11.5)]),
      gridAutoRows(`rem(19.3)),
      gridColumnGap(`rem(1.)),
      gridRowGap(`rem(2.)),
      media(
        Theme.MediaQuery.tablet,
        [
          gridTemplateColumns([
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
          ]),
        ],
      ),
      media(
        Theme.MediaQuery.desktop,
        [
          gridTemplateColumns([
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
            `rem(11.5),
          ]),
        ],
      ),
    ]);

  let advisorGrid =
    style([
      display(`grid),
      gridTemplateColumns([`repeat((`num(2), `rem(11.5)))]),
      gridAutoRows(`rem(20.)),
      gridColumnGap(`rem(1.)),
      gridRowGap(`rem(2.)),
      paddingBottom(`rem(4.)),
      media(
        Theme.MediaQuery.tablet,
        [gridTemplateColumns([`repeat((`num(4), `rem(11.5)))])],
      ),
      media(
        Theme.MediaQuery.desktop,
        [gridTemplateColumns([`repeat((`num(6), `rem(11.5)))])],
      ),
    ]);

  let advisors =
    merge([
      Theme.Type.h3,
      style([marginTop(`rem(2.)), marginBottom(`rem(0.5))]),
    ]);

  let advisorsSubhead =
    merge([Theme.Type.sectionSubhead, style([marginBottom(`rem(2.))])]);
};

[@react.component]
let make =
    (~profiles, ~advisors, ~switchModalState, ~setCurrentIndexAndMembers) => {
  <>
    <h2 id="team" className=Styles.advisors> {React.string("Directors")} </h2>
    <p className=Styles.advisorsSubhead>
      {React.string("Mina Foundation Board of Directors")}
    </p>
    <div className=Styles.advisorGrid>
      {React.array(
         advisors
         |> Array.map((member: ContentType.GenericMember.t) => {
              <div
                key={member.name}
                onClick={_ => {
                  switchModalState();
                  setCurrentIndexAndMembers(member, advisors);
                }}>
                <SmallCard member />
              </div>
            }),
       )}
    </div>
    <h2 className=Styles.header> {React.string("Contributors")} </h2>
    <p className=Styles.sectionSubhead>
      {React.string(
         "Mina is an inclusive open source protocol uniting teams and technicians from San Francisco and around the world.",
       )}
    </p>
    <Spacer height=2. />
    <Rule color=Theme.Colors.digitalBlack />
    <div className=Styles.grid>
      {React.array(
         profiles
         |> Array.map((member: ContentType.GenericMember.t) => {
              <div
                key={member.name}
                onClick={_ => {
                  switchModalState();
                  setCurrentIndexAndMembers(member, profiles);
                }}>
                <SmallCard member />
              </div>
            }),
       )}
    </div>
  </>;
};
