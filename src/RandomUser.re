type picture = {medium: string};

type name = {
  title: string,
  first: string,
  last: string,
};

type dob = {date: string};

type location = {
  city: string,
  state: string,
};

type randomUser = {
  gender: string,
  picture,
  name,
  dob,
  location,
  phone: string,
  email: string,
};

module GetRandomUser = [%graphql
  {|
    {
      randomUser @bsRecord {
        gender
        picture @bsRecord {
          medium
        }
        name @bsRecord {
          title
          first
          last
        }

        dob @bsRecord {
          date
        }

        location @bsRecord {
          city
          state
        }

        phone

        email
      }
    }
  |}
];

module GetRandomUserComponent = ReasonApollo.CreateQuery(GetRandomUser);

let fullname = (profile: randomUser) => {
  let {name} = profile;
  name.title ++ ". " ++ name.first ++ " " ++ name.last;
};

let formatDate = (date: Js.Date.t) => {
  let year = Js.Date.getFullYear(date);
  let day = Js.Date.getDate(date);
  let month = Js.Date.getMonth(date) +. 1.;

  Js.Float.(
    toString(day) ++ "/" ++ toString(month) ++ "/" ++ toString(year)
  );
};

module Profile = {
  [@react.component]
  let make = (~profile: randomUser) => {
    <div>
      <div className="tc">
        <img className="br-100" src={profile.picture.medium} />
        <Mui.Typography variant="h6">
          {profile->fullname->React.string}
        </Mui.Typography>
        <hr className="mw3 bb bw1 b--black-10" />
      </div>
      <Mui.List>
        <Mui.ListItem>
          <Mui.ListItemIcon> <Mui.Icon.CakeIcon /> </Mui.ListItemIcon>
          <Mui.ListItemText
            primary={profile.dob.date->Js.Date.fromString->formatDate}
          />
        </Mui.ListItem>
        <Mui.ListItem>
          <Mui.ListItemIcon> <Mui.Icon.LocationCityIcon /> </Mui.ListItemIcon>
          <Mui.ListItemText
            primary={profile.location.city ++ ", " ++ profile.location.state}
          />
        </Mui.ListItem>
        <Mui.ListItem>
          <Mui.ListItemIcon> <Mui.Icon.PhoneIcon /> </Mui.ListItemIcon>
          <Mui.ListItemText
            primary=profile.phone
          />
        </Mui.ListItem>
        <Mui.ListItem>
          <Mui.ListItemIcon> <Mui.Icon.EmailIcon /> </Mui.ListItemIcon>
          <Mui.ListItemText
            primary=profile.email
          />
        </Mui.ListItem>
      </Mui.List>
    </div>;
  };
};

[@react.component]
let make = () => {
  <Mui.Paper elevation=`elevation3 className="pv3 ph2">
    <GetRandomUserComponent>
      {({result}) =>
         switch (result) {
         | Loading => <CenteredLoader />
         | Error(e) =>
           <Mui.Typography variant="body1">
             {React.string("Cannot fetch a random user: " ++ e##message)}
           </Mui.Typography>
         | Data(data) =>
           let user = data##randomUser;
           <div> <Profile profile=user /> </div>;
         }}
    </GetRandomUserComponent>
  </Mui.Paper>;
};