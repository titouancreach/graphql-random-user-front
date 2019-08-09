[@react.component]
let make = () => {
  <div>
    <Mui.AppBar position=`static>
      <Mui.Toolbar>
        <Mui.IconButton edge=`start color=`inherit_ aria_label="menu">
          <Mui.Icon.MenuIcon />
        </Mui.IconButton>
        <Mui.Typography variant="h6" className="flex-grow-1">
          {React.string("Profile")}
        </Mui.Typography>
        <div>
          <Mui.IconButton aria_label="show 4 new mails" color=`inherit_>
            <Mui.Badge badgeContent=4 color=`secondary>
              <Mui.Icon.MailIcon />
            </Mui.Badge>
          </Mui.IconButton>
          <Mui.IconButton
            aria_label="show 17 new notifications" color=`inherit_>
            <Mui.Badge badgeContent=17 color=`secondary>
              <Mui.Icon.NotificationsIcon />
            </Mui.Badge>
          </Mui.IconButton>
        </div>
      </Mui.Toolbar>
    </Mui.AppBar>
    <Mui.Container className="pv2"> <RandomUser /> </Mui.Container>
  </div>;
};