$Id$

-- SUMMARY --

The Cludo Search module provides a form and javascript call to obtain results from your Cludo search account. 

The module can act as a replacement for core Search, or it may operate in tandem with it. 

Cludo search results are called from here: csearch/{search terms}. 

This module simply defines the search form block, and results page.


-- REQUIREMENTS --

For this module to function, it requires the following:

1. Cludo account (the account is a paid item, and this module is unaffiliated with the Cludo organization)
2. Cludo must have "crawled your site"
3. Any and all configurations to the Cludo account
4. A valid Cludo account

Without the above, this module will do nothing of interest.


-- INSTALLATION --

Install in Drupal the normal way...

  * http://drupal.org/documentation/install/modules-themes/modules-7

-- CONFIGURATION --

The module needs to be configured to connect to your CS device, which can be found here...

  * admin/config/search/cludo_search/settings
  
The configuration interface can be in the search area on the configuration page.

-- BLOCKS --

The module provides one block, and a results page:

  (1) Search Form


The search page:

  * csearch/

No records of you search content are stored on your server.

-- TESTING --


  (1) Basic testing that doesn't require a connection to your CS

