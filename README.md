Rules Once per Day
==================

Rules Once Per Day provides an event for Rules that is triggered once per day by
cron, at or soon after the specified hour of the day, along with conditions that
let you trigger actions once per week, month, or quarter.


Installation and Configuration
------------------------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules.

- Visit the configuration page at Configuration > Workflow > Rules > Once per
Day (admin/config/workflow/rules/rules_onceperday) and select the hour of the
day for the daily event.


Usage
-----

Define Rules using the provided "Once per day" event, and optionally also
using the provided conditions for day of the week, day of the month, and/or day
of the quarter.

The module includes a definition for a default disabled rule, that shows how an email can be sent once a week every Monday.


Documentation
-------------

Additional documentation is located in the Wiki:
https://github.com/backdrop-contrib/rules-onceperday/wiki/Documentation.


Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/rules-onceperday/issues.


Current Maintainers
-------------------

- [Robert J. Lang](https://github.com/bugfolder).


Credits
-------

- Ported to Backdrop CMS by [Robert J. Lang](https://github.com/bugfolder).
- [Originally written for Drupal](http://drupal.org/project/rules_onceperday) by Anthony Cartmell, <ajcartmell@fonant.com>.

License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.
