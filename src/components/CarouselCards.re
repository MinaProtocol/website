module Styles = {
  open Css;
  let outerBox = style([padding2(~v=`rem(0.), ~h=`rem(0.))]);
  let container = dark =>
    style([
      display(`flex),
      flexDirection(`column),
      paddingBottom(`rem(3.)),
      width(`percent(100.)),
      height(`rem(36.)),
      dark
        ? background(Theme.Colors.digitalBlack) : background(`hex("F5F5F5")),
      padding2(~h=`rem(2.5), ~v=`rem(3.)),
    ]);

  let grantContainer = dark =>
    merge([container(dark), style([height(`rem(50.))])]);

  let memberName = dark =>
    merge([
      Theme.Type.h3,
      style([
        dark ? color(Theme.Colors.white) : color(Theme.Colors.digitalBlack),
        marginTop(`rem(1.)),
        fontWeight(`light),
        maxWidth(`rem(18.)),
      ]),
    ]);
  let profilePicture =
    style([
      background(white),
      marginTop(`rem(-5.5)),
      height(`rem(7.75)),
      width(`rem(8.125)),
    ]);
  let link =
    merge([
      Theme.Type.metadata,
      style([textDecoration(`none), hover([color(Theme.Colors.orange)])]),
    ]);
  let memberTitle = dark =>
    merge([
      Theme.Type.label,
      style([
        dark ? color(Theme.Colors.white) : color(Theme.Colors.digitalBlack),
        fontSize(`rem(0.875)),
        width(`percent(100.)),
        maxWidth(`rem(18.)),
        marginTop(`rem(0.51)),
        media(
          Theme.MediaQuery.tablet,
          [fontSize(`px(12)), lineHeight(`px(16))],
        ),
      ]),
    ]);
  let quoteSection = dark =>
    merge([
      Theme.Type.paragraph,
      style([
        dark ? color(Theme.Colors.white) : color(Theme.Colors.digitalBlack),
        width(`rem(18.)),
        marginTop(`rem(1.)),
      ]),
    ]);
  let quote = style([marginTop(`rem(1.5)), marginBottom(`rem(1.5))]);
  let socials =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      alignItems(`center),
      flexDirection(`row),
      width(`rem(18.)),
      marginTop(`auto),
    ]);
  let location =
    style([
      display(`flex),
      alignItems(`center),
      marginBottom(`rem(0.5)),
      selector("p", [marginTop(`zero), marginBottom(`zero)]),
    ]);
  let socialTags =
    style([
      display(`flex),
      flexDirection(`row),
      justifyContent(`spaceBetween),
      maxWidth(`rem(15.)),
      selector("> :first-child", [marginLeft(`zero)]),
    ]);
  let iconLink = dark =>
    style([
      dark ? color(Theme.Colors.white) : color(Theme.Colors.digitalBlack),
      marginLeft(`rem(1.)),
    ]);
  let profileRow =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      width(`percent(100.)),
    ]);
  let icon = style([cursor(`pointer)]);

  let contributor = style([color(Theme.Colors.orange)]);

  let repoButton =
    style([color(Theme.Colors.orange), marginTop(`rem(2.5))]);

  let projectLink =
    merge([
      Theme.Type.link,
      style([
        display(`flex),
        alignItems(`center),
        color(Theme.Colors.orange),
        marginTop(`rem(1.)),
      ]),
    ]);
};

module GenesisMemberCard = {
  [@react.component]
  let make = (~member: ContentType.GenesisProfile.t, ~dark) => {
    let {
      ContentType.GenesisProfile.name,
      image,
      quote,
      twitter,
      github,
      memberLocation,
    } = member;
    <div className=Styles.outerBox>
      <div className={Styles.container(dark)}>
        <div className=Styles.profileRow>
          <img
            src={image.fields.file.url}
            alt=name
            className=Styles.profilePicture
          />
        </div>
        <h4 className={Styles.memberName(dark)}> {React.string(name)} </h4>
        <p className={Styles.memberTitle(dark)}>
          {React.string("Genesis Founding Member")}
        </p>
        <div className={Styles.quoteSection(dark)}>
          <Rule />
          {switch (quote) {
           | Some(q) =>
             <p className=Styles.quote> {React.string({j|"$(q)"|j})} </p>
           | None => React.null
           }}
          <Rule />
        </div>
        <div className=Styles.socials>
          <>
            <div className=Styles.location>
              <Icon kind=Icon.Location />
              <Spacer width=0.3 />
              <p className=Theme.Type.paragraphMono>
                {React.string(memberLocation)}
              </p>
            </div>
          </>
          <div className=Styles.socialTags>
            {switch (twitter) {
             | Some(twitter) =>
               <a
                 target="_blank"
                 rel="noopener"
                 href={Constants.twitterUrl ++ twitter}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.Twitter />
               </a>
             | _ => React.null
             }}
            {switch (github) {
             | Some(github) =>
               <a
                 target="_blank"
                 rel="noopener"
                 href={Constants.githubUrl ++ github}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.Github />
               </a>
             | _ => React.null
             }}
          </div>
        </div>
      </div>
    </div>;
  };
};

module GrantCard = {
  [@react.component]
  let make = (~grant: ContentType.Grant.t, ~dark) => {
    let {
      ContentType.Grant.title,
      grantType,
      contributer,
      description,
      repoSlug,
      projectSlug,
    } = grant;
    <div className=Styles.outerBox>
      <div className={Styles.grantContainer(dark)}>
        <h4 className={Styles.memberName(dark)}> {React.string(title)} </h4>
        <p className={Styles.memberTitle(dark)}>
          {React.string("Contributor: ")}
          <span className=Styles.contributor>
            {React.string(contributer)}
          </span>
        </p>
        {Belt.Option.mapWithDefault(grantType, React.null, grantType => {
           <p className={Styles.memberTitle(dark)}>
             {React.string("TYPE: " ++ grantType)}
           </p>
         })}
        <div className={Styles.quoteSection(dark)}>
          <Rule />
          <p className=Styles.quote> {React.string(description)} </p>
          <Rule />
        </div>
        <div>
          {Belt.Option.mapWithDefault(projectSlug, React.null, projectSlug => {
             <a href=projectSlug className=Styles.projectLink>
               <span> {React.string("Link to Project")} </span>
               <Icon kind=Icon.ArrowRightMedium />
             </a>
           })}
          {Belt.Option.mapWithDefault(repoSlug, React.null, repoSlug => {
             <div className=Styles.repoButton>
               <Button href={`External(repoSlug)} bgColor=Theme.Colors.white>
                 <span> {React.string("Repo")} </span>
                 <span className=Styles.contributor>
                   <Icon kind=Icon.ArrowRightSmall />
                 </span>
               </Button>
             </div>
           })}
        </div>
      </div>
    </div>;
  };
};

module TeamMemberCard = {
  [@react.component]
  let make = (~member, ~dark) => {
    let {ContentType.TeamProfile.name, title, image, quote, twitter, github} = member;
    <div className=Styles.outerBox>
      <div className={Styles.container(dark)}>
        <div className=Styles.profileRow>
          <img
            src={image.fields.file.url}
            alt=name
            className=Styles.profilePicture
          />
        </div>
        <h4 className={Styles.memberName(dark)}> {React.string(name)} </h4>
        <p className={Styles.memberTitle(dark)}> {React.string(title)} </p>
        <div className={Styles.quoteSection(dark)}>
          <Rule />
          {switch (quote) {
           | Some(q) =>
             <p className=Styles.quote> {React.string({j|"$(q)"|j})} </p>
           | None => React.null
           }}
          <Rule />
        </div>
        <div className=Styles.socials>
          <div className=Styles.socialTags>
            {switch (twitter) {
             | Some(twitter) =>
               <a
                 target="_blank"
                 rel="noopener"
                 href={Constants.twitterUrl ++ twitter}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.Twitter />
               </a>
             | _ => React.null
             }}
            {switch (github) {
             | Some(github) =>
               <a
                 target="_blank"
                 rel="noopener"
                 href={Constants.githubUrl ++ github}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.Github />
               </a>
             | _ => React.null
             }}
            {switch (member.linkedin) {
             | Some(linkedIn) =>
               <a
                 target="_blank"
                 rel="noopener"
                 href={Constants.linkedInUrl ++ linkedIn}
                 className={Styles.iconLink(dark)}>
                 <Icon kind=Icon.LinkedIn />
               </a>
             | _ => React.null
             }}
          </div>
        </div>
      </div>
    </div>;
  };
};
