// $Id$

The Mentions module adds a filter to convert [@username] or [@#uid] patterns to
a link to the user's profile page, in a similar way @username is used on Twitter.

The module will also track all @username mentions as of the stable release, allowing
users to view all content that references their @username.

Mentions was written and is maintained by Stuart Clark (deciphered).
- http://stuar.tc/lark


Features
-------------------

* Coverts [@username] to a link to the user's profile.
* Coverts [@#uid] to a link to the user's profile.


Usage/Configuration
-------------------

Once installed, @username needs to be enabled on your desired content types,
this can be done via the 'Input formats' configuration page.
http://[www.yoursite.com/path/to/drupal]/admin/settings/filters

