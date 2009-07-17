// $Id$

The Mentions module offers Twitter like functionality, recording all references
to a user's username - using the [@username] or [@#uid] filter format - in all
Nodes and Comments, providing a centralized page to track all mentions.

Mentions was written and is maintained by Stuart Clark (deciphered).
- http://stuar.tc/lark


Features
-------------------

* An Input filter to convert [@username] or [@#uid] to the user's profile.
* Views integration, including a default page view for tracking mentions.
  * http://[www.yoursite.com/path/to/drupal]/user/[#uid]/mentions


Usage/Configuration
-------------------

Once installed, the Mentions filter needs to be enabled on your desired content
types, this can be done via the Input formats configuration page.
* http://[www.yoursite.com/path/to/drupal]/admin/settings/filters
