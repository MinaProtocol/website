module Styles = {
    open Css;

    let container = {
        style([
            paddingTop(`rem(2.)),
            marginBottom(`rem(3.)),
            borderBottom(`px(1), `solid, Theme.Colors.digitalBlack),
        ])
    }

    let containerSm = {
        style([
            marginTop(`rem(2.)),
            marginBottom(`rem(2.)),
            selector(
                "button",
                [
                    color(Theme.Colors.digitalBlack),
                ],
            ),
        ])
    }

    let h1 = {
        style([
            fontSize(`px(46)),
            marginBottom(`rem(3.)),
            padding(`rem(2.)),
            Theme.Typeface.monumentGrotesk,
            fontWeight(`normal),
            color(Theme.Colors.digitalBlack),
                media(
                    Theme.MediaQuery.tablet,
                    [
                        padding(`rem(1.)),
                        marginLeft(`rem(0.7)),
                    ],
                ),
                media(
                    Theme.MediaQuery.mobile,
                    [
                       fontSize(`px(32)),
                       marginLeft(`rem(0.7)),
                    ],
                ),
            ])
    }

    let heading = {
        style([
            Theme.Typeface.monumentGrotesk,
            fontSize(`px(20)),
            fontWeight(`num(400)),
            lineHeight(`px(30)),
            color(Theme.Colors.digitalBlack),

            media(
                Theme.MediaQuery.mobile,
                [
                    padding(`rem(1.)),
                ],
            ),
            media(
                Theme.MediaQuery.tablet,
                [
                    padding(`rem(1.)),
                ],
            ),
            media(
                Theme.MediaQuery.desktop,
                [
                    paddingLeft(`rem(0.)),
                    paddingRight(`rem(0.)),
                    paddingBottom(`rem(1.)),
                    paddingTop(`rem(1.)),
                ],
            ),
        ])
    }

    let headingSub = {
        style([
            Theme.Typeface.monumentGrotesk,
            fontSize(`px(18)),
            fontWeight(`num(400)),
            lineHeight(`px(27)),
            color(Theme.Colors.digitalBlack),

            media(
                Theme.MediaQuery.mobile,
                [
                    padding(`rem(1.)),
                ],
            ),
            media(
                Theme.MediaQuery.tablet,
                [
                    padding(`rem(1.)),
                ],
            ),
            media(
                Theme.MediaQuery.desktop,
                [
                    paddingLeft(`rem(0.)),
                    paddingRight(`rem(0.)),
                    paddingBottom(`rem(1.)),
                    paddingTop(`rem(1.)),
                ],
            ),
        ])
    }

    let blockNameText = {
        style([
            Theme.Typeface.monumentGrotesk,
            fontSize(`px(24)),
            fontWeight(`num(400)),
            lineHeight(`px(28)),
            color(Theme.Colors.digitalBlack),
        ])
    }

    let rewardsBodyMain = {
        style([
            Theme.Typeface.monumentGrotesk,
            fontSize(`px(18)),
            fontWeight(`num(400)),
            lineHeight(`px(27)),
            color(Theme.Colors.digitalBlack),
        ])
    }

    let rewardsBodySub = {
        style([
            Theme.Typeface.monumentGrotesk,
            fontSize(`px(18)),
            fontWeight(`num(400)),
            lineHeight(`px(27)),
            color(Theme.Colors.greyScale),
        ])
    }

    let section = {
        style([
            borderTop(`px(1), `solid, Theme.Colors.digitalBlack),
            paddingTop(`rem(1.)),
            paddingBottom(`rem(1.)),
        ])
    }

    let headBlock = {
        style([
            display(`flex),
            media(
                Theme.MediaQuery.desktop,
                [
                    marginTop(`rem(-1.)),
                ],
            ),
            media(
                Theme.MediaQuery.mobile,
                [
                    display(`block),
                ],
              ),
        ])
    }

    let headCol1 = {
        style([
            width(`percent(35.)),
            media(
                Theme.MediaQuery.mobile,
                [
                    width(`percent(100.)),
                ],
              ),
        ])
    }

    let headCol2 = {
        style([
            display(`none),
            media(
                Theme.MediaQuery.desktop,
                [
                    display(`flex),
                    flexDirection(`column),
                    width(`percent(40.)),
                    margin(`rem(0.5)),
                    marginTop(`rem(-0.2)),
                ],
              ),
        ])
    }


    let col1 = {
        style([
            margin(`rem(0.5)),
            width(`percent(50.)),
            media(
                Theme.MediaQuery.desktop,
                [
                    margin(`rem(0.5)),
                    width(`percent(35.)),
                ],
              ),
              media(
                Theme.MediaQuery.mobile,
                [
                    margin(`rem(0.5)),
                    width(`percent(100.)),
                ],
              ),

        ])
    }
    let col2 = {
        style([
            margin(`rem(0.5)),
            display(`none),
            media(
                Theme.MediaQuery.desktop,
                [
                    display(`flex),
                    flexDirection(`column),
                    width(`percent(40.)),
                    marginTop(`rem(2.6)),
                ],
              ),
        ])
    }
    let col3 = {
        style([
            margin(`rem(0.5)),
            width(`percent(50.)),
            display(`flex),
            justifyContent(`flexEnd),
             media(
                Theme.MediaQuery.desktop,
                [
                    display(`flex),
                    justifyContent(`center),
                    margin(`rem(0.5)),
                    width(`percent(25.)),
                    marginTop(`rem(2.6)),
                ],
              ),
              media(
                Theme.MediaQuery.mobile,
                [
                    display(`flex),
                    justifyContent(`flexStart),
                    margin(`rem(0.5)),
                    width(`percent(100.)),
                ],
              ),
        ])
    }

    let block = {
        style([
            display(`flex),
            justifyContent(`spaceBetween),
            alignItems(`center),
            padding(`rem(1.)),
            media(
                Theme.MediaQuery.mobile,
                [
                    display(`block),
                ],
              ),
        ])
    }
    let accordianBlock = {
        style([
            display(`flex),
            justifyContent(`flexEnd),
            width(`percent(100.)),
            alignItems(`center),
            padding(`rem(2.)),
            media(
                Theme.MediaQuery.mobile,
                [
                    display(`block),
                ],
              ),
        ])
    }

    let accordianCol = {
        style([
            width(`percent(100.)),
            media(
                Theme.MediaQuery.desktop,
                [
                    width(`percent(65.)),
                ],
              ),
        ])
    }

    let accordianContaner = {
        style([
            paddingTop(`rem(0.5)),
            paddingBottom(`rem(1.))
        ])
    }

    let tableContaner = {
        style([
            borderBottom(`px(1), `solid, Theme.Colors.digitalBlack),
            borderTop(`px(1), `solid, Theme.Colors.digitalBlack),
            paddingTop(`rem(1.)),
            paddingBottom(`rem(1.))
        ])
    }

    let accordianHead = {
        style([
            display(`flex),
            paddingTop(`rem(1.)),
            media(
                Theme.MediaQuery.mobile,
                [
                    display(`block),
                ],
            ),
        ])
    }

    let list = {
        style([
            listStylePosition(`outside),
            paddingLeft(`rem(1.)),
            marginBottom(`rem(1.)),
        ])
    }

    let listItem = {
        style([
            paddingBottom(`rem(0.5)),
            Theme.Typeface.monumentGrotesk,
            fontSize(`px(16)),
            fontWeight(`num(400)),
            lineHeight(`px(24)),
            color(Theme.Colors.digitalBlack),
        ])
    }

    let link = {
        merge([
            Theme.Type.link,
            style([
                marginLeft(`rem(0.5)),
                display(`flex),
                alignItems(`center),
            ])
        ])
    }

     let inLineLink = {
        merge([
            Theme.Type.link,
            style([
                fontSize(`px(16)),
            ])
        ])
    }
    
    let table = {
        style([
            width(`percent(100.))
        ])
    }

    let tableHeadContainer = {
        style([
            display(`flex),
            alignItems(`center),
        ])
    }
    let tableBodySection = {
        style([
            display(`flex),
            flexWrap(`wrap),
            alignItems(`center),
            fontSize(`px(300)),
        ])
    }

    let tableHead = {
        style([
            flex(`num(1.)),
            textAlign(`center),
            padding(`rem(0.5)),
            borderBottom(`px(1), `solid, Theme.Colors.digitalBlack),
            Theme.Typeface.monumentGrotesk,
            fontSize(`px(14)),
            fontWeight(`num(400)),
            lineHeight(`px(16)),
            color(Theme.Colors.digitalBlack),
        ])
    }

    let tableBody = {
        style([
            width(`percent(50.)),
            textAlign(`center),
            padding(`rem(0.5)),
            Theme.Typeface.monumentGrotesk,
            fontSize(`px(16)),
            fontWeight(`num(400)),
            lineHeight(`px(24)),
            background(Theme.Colors.lightGray),
            selector(":nth-child(4n), :nth-child(4n-1)", [
                background(Theme.Colors.white)
            ]),
        ])
    }

    let disclaimerText = {
        style([
            Theme.Typeface.monumentGrotesk,
            fontSize(`px(14)),
            fontWeight(`num(400)),
            lineHeight(`px(16)),
            color(Theme.Colors.digitalBlack),
            opacity(0.5),
            marginBottom(`rem(1.)),
            marginBottom(`rem(3.)),
        ])
    }
};

module Header = {
    [@react.component]
    let make = (~children, ~title) => {
        <div className=Styles.container>
            <h1 className=Styles.h1 id="challenges"> {React.string(title)} </h1>
        children
        </div>
    }
}

module Contanier = {
    [@react.component]
    let make = (~children, ~title1, ~title2) => {
            <div className=Styles.section>
                <div className=Styles.headBlock>
                    <div className=Styles.headCol1>
                        <p className=Styles.heading>{React.string(title1)}</p>
                    </div>
                    <div className=Styles.headCol2>
                        <p className=Styles.heading>{React.string(title2)}</p>
                    </div>
                </div>
                children
            </div>
    }
}

module Item = {
    [@react.component]
    let make = (~children ,~title, ~rewardsMain, ~rewardsSub) => {
        let (showAccordian, setShowAccordian) = React.useState(() => false);
        <>
            <div className=Styles.block>
                <div className=Styles.col1>
                    <p className=Styles.blockNameText>{React.string(title)}</p>
                </div>
                <div className=Styles.col2>
                    <p className=Styles.rewardsBodyMain>{React.string(rewardsMain)}</p>
                    <p className=Styles.rewardsBodySub>{React.string(rewardsSub)}</p>
                </div>
                <div className=Styles.col3>
                    <Button 
                        onClick={e => {
                            ReactEvent.Mouse.preventDefault(e);
                            setShowAccordian(_ => !showAccordian)
                        }}
                        href=`Scroll_to_top 
                        bgColor=Theme.Colors.black
                    >
                        { showAccordian 
                            ?
                                <> 
                                    {React.string("Hide Details")}
                                    <Icon kind=Icon.ChevronUp />
                                </>
                            : 
                                <>
                                    {React.string("View Details")}
                                    <Icon kind=Icon.ChevronDown /> 
                                </>
                        }
                    </Button>
                </div>
            </div>
            {showAccordian ?  children : React.null
            }
        </>
    };
}

module RewardsTable = {
    [@react.component]
    let make = (~title, ~tableHead, ~tableRow)=> {
         <div className=Styles.tableContaner>
            <p className=Styles.heading>{React.string(title)}</p>
            <div className=Styles.table>
                <div className=Styles.tableHeadContainer>
                    <p className=Styles.tableHead>{React.string(tableHead[0])}</p>
                    <p className=Styles.tableHead>{React.string(tableHead[1])}</p>
                </div>

                <div className=Styles.tableBodySection>
                {
                    tableRow
                    ->Belt.Array.map(item => 
                        <p className=Styles.tableBody>{React.string(item)}</p>
                    )
                    ->React.array
                }
                </div>

            </div>
        </div>
    }
}

module BonusTable = {
    [@react.component]
    let make = (~tableHead, ~tableRow)=> {
         <div className=Styles.accordianContaner>
            <div className=Styles.table>
                <div className=Styles.tableHeadContainer>
                    <p className=Styles.tableHead>{React.string(tableHead[0])}</p>
                    <p className=Styles.tableHead>{React.string(tableHead[1])}</p>
                </div>

                <div className=Styles.tableBodySection>
                {
                    tableRow
                    ->Belt.Array.map(item => 
                        <p className=Styles.tableBody>{React.string(item)}</p>
                    )
                    ->React.array
                }
                </div>

            </div>
        </div>
    }
}

module List = {
    [@react.component]
    let make = (~title, ~rules) => {
        <div className=Styles.accordianContaner>
            <h4 className=Styles.heading>{React.string(title)}</h4>
            <ul className=Styles.list>
            {
                rules
                ->Belt.Array.map(item => 
                    <li className=Styles.listItem>{React.string(item)}</li>
                )
                ->React.array
            }
            </ul>
        </div>      
    }
}

module Link = {
    [@react.component]
    let make = (~title) => {
        <a className=Styles.link> 
            {React.string(title)} 
            <Icon kind=Icon.ArrowRightMedium />
        </a>
    }
}

module Accordian = {
    [@react.component]
    let make = (~children) => {
         <>
            <div className=Styles.accordianBlock>
                <div className=Styles.accordianCol>
                    children
                </div>
            </div>
        </>
    }
}

module Disclaimer = {
    [@react.component]
    let make = (~title)=> {
        <p className=Styles.disclaimerText>{React.string(title)}</p>
    }
}

module ContainerSm = {
    [@react.component]
    let make = (~children)=> {
        <div className=Styles.containerSm>
            children
        </div>
    }
}

module TransactionRules = {
    [@react.component]
    let make = (~title) => {
        <div className=Styles.accordianContaner>
            <h4 className=Styles.heading>{React.string(title)}</h4>
            <ul className=Styles.list>
                <li className=Styles.listItem><p>{React.string("Send as many transactions as you can. ")}</p></li>
                <li className=Styles.listItem><p>{React.string("Transactions can be sent to any address in the network.")}</p></li>
                <li className=Styles.listItem>
                    <span>{React.string("Winners will be awarded testnet leaderboard points.* Participants with high leaderboard scores at the end of our testnet will be invited to join Mina's ")}</span>
                    <span className=Styles.inLineLink>{React.string("Genesis Program")} </span>
                    <span>{React.string(", and will be eligible for ")} </span>
                    <span className=Styles.inLineLink>{React.string("bonus rewards.")} </span>
                </li>
                
            </ul>
        </div>      
    }
}

module SnarkRules = {
    [@react.component]
    let make = (~title) => {
        <div className=Styles.accordianContaner>
            <h4 className=Styles.heading>{React.string(title)}</h4>
            <ul className=Styles.list>
                <li className=Styles.listItem><p>{React.string("Produce as many SNARKs as you can")}</p></li>
                <li className=Styles.listItem>
                    <span>{React.string("Winners will be awarded testnet leaderboard points.* Participants with high leaderboard scores at the end of our testnet will be invited to join ")}</span>
                    <span className=Styles.inLineLink>{React.string("Mina's Genesis Program")} </span>
                    <span>{React.string(", and will be eligible for ")} </span>
                    <span className=Styles.inLineLink>{React.string("bonus rewards.")} </span>
                </li>
                
            </ul>
        </div>      
    }
}

module ProduceBlockRules = {
    [@react.component]
    let make = (~title) => {
        <div className=Styles.accordianContaner>
            <h4 className=Styles.heading>{React.string(title)}</h4>
            <ul className=Styles.list>
                <li className=Styles.listItem><p>{React.string("Produce as many blocks as you can")}</p></li>
                <li className=Styles.listItem>
                    <span>{React.string("Winners will be awarded testnet leaderboard points.* Participants with high leaderboard scores at the end of our testnet will be invited to join ")}</span>
                    <span className=Styles.inLineLink>{React.string("Mina's Genesis Program")} </span>
                    <span>{React.string(", and will be eligible for ")} </span>
                    <span className=Styles.inLineLink>{React.string("bonus rewards.")} </span>
                </li>
                
            </ul>
        </div>      
    }
}