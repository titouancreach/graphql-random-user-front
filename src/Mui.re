module Button = {
  [@bs.module "@material-ui/core/Button"] [@react.component]
  external make: (~children: React.element) => React.element = "default";
};

module AppBar = {
  [@bs.module "@material-ui/core/AppBar"] [@react.component]
  external make:
    (
      ~children: React.element,
      ~position: [@bs.string] [
                   | `static
                   | `fixed
                   | `absolute
                   | `relative
                   | `sticky
                 ]
                   =?
    ) =>
    React.element =
    "default";
};

module Toolbar = {
  [@bs.module "@material-ui/core/Toolbar"] [@react.component]
  external make: (~children: React.element) => React.element = "default";
};

module Icon = {
  module MenuIcon = {
    [@bs.module "@material-ui/icons/Menu"] [@react.component]
    external make: unit => React.element = "default";
  };
  module MailIcon = {
    [@bs.module "@material-ui/icons/Mail"] [@react.component]
    external make: unit => React.element = "default";
  };
  module NotificationsIcon = {
    [@bs.module "@material-ui/icons/Notifications"] [@react.component]
    external make: unit => React.element = "default";
  };

  module CakeIcon = {
    [@bs.module "@material-ui/icons/Cake"] [@react.component]
    external make: unit => React.element = "default";
  };


  module LocationCityIcon = {
    [@bs.module "@material-ui/icons/LocationCity"] [@react.component]
    external make: unit => React.element = "default";
  };


  module PhoneIcon = {
    [@bs.module "@material-ui/icons/Phone"] [@react.component]
    external make: unit => React.element = "default";
  }
  module EmailIcon = {
    [@bs.module "@material-ui/icons/Email"] [@react.component]
    external make: unit => React.element = "default";
  }
};

module IconButton = {
  [@bs.module "@material-ui/core/IconButton"] [@react.component]
  external make:
    (
      ~children: React.element=?,
      ~edge: [@bs.string] [ | `start]=?,
      ~className: string=?,
      ~color: [@bs.string] [ | [@bs.as "inherit"] `inherit_]=?,
      ~aria_label: string=?
    ) =>
    React.element =
    "default";
};

module Typography = {
  [@bs.module "@material-ui/core/Typography"] [@react.component]
  external make:
    (~children: React.element, ~variant: string, ~className: string=?) =>
    React.element =
    "default";
};

module Badge = {
  [@bs.module "@material-ui/core/Badge"] [@react.component]
  external make:
    (
      ~children: React.element,
      ~color: [@bs.string] [ | `primary | `secondary],
      ~badgeContent: int
    ) =>
    React.element =
    "default";
};

module Container = {
  [@bs.module "@material-ui/core/Container"] [@react.component]
  external make:
    (~children: React.element, ~className: string=?) => React.element =
    "default";
};

module Paper = {
  [@bs.module "@material-ui/core/Paper"] [@react.component]
  external make:
    (
      ~children: React.element=?,
      ~className: string=?,
      ~elevation: [@bs.int] [
                    | `elevation0
                    | `elevation1
                    | `elevation3
                    | `elevation4
                    | `elevation5
                    | `elevation6
                    | `elevation7
                    | `elevation8
                    | `elevation9
                    | `elevation10
                  ]
                    =?
    ) =>
    React.element =
    "default";
};

module CircularProgress = {
  [@bs.module "@material-ui/core/CircularProgress"] [@react.component]
  external make:
    (
      ~color: [@bs.string] [ | `primary | `secondary]=?,
      ~className: string=?
    ) =>
    React.element =
    "default";
};

module List = {
  [@bs.module "@material-ui/core/List"] [@react.component]
  external make: (~children: React.element=?) => React.element = "default"
}

module ListItem = {
  [@bs.module "@material-ui/core/ListItem"] [@react.component]
  external make: (~children: React.element=?) => React.element = "default"
}

module ListItemIcon = {
  [@bs.module "@material-ui/core/ListItemIcon"] [@react.component]
  external make: (~children: React.element=?) => React.element = "default"
}
module ListItemText = {
  [@bs.module "@material-ui/core/ListItemText"] [@react.component]
  external make: (~children: React.element=?, ~primary: string) => React.element = "default"
}