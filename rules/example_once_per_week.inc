<?php

$rule = '{ "rules_once_per_week" : {
    "LABEL" : "Example once per week",
    "ACTIVE" : false,
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "onceperday", "rules" ],
    "ON" : { "once_per_day" : [] },
    "IF" : [ { "onceperday_condition_dayofweek" : { "text1" : "1" } } ],
    "DO" : [
      { "mail" : {
          "to" : "mail@example.com",
          "subject" : "It is a Monday!",
          "message" : "Once a week message sent [site:current-date]",
          "language" : [ "" ]
        }
      }
    ]
  }
}';