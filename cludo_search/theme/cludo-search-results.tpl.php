<?php
// $Id$
/**
 * @file 
 *    default theme implementation for displaying cludo Search search results
 *
 * This template collects each invocation of theme_cludo_search_result(). This and
 * the child template are dependent on one another sharing the markup for the 
 * results listing
 *
 * @see cludo-search-result.tpl.php
 */
?>
<?php print drupal_render($search_form); ?>
<?php print drupal_render($form); ?>
<?php  print drupal_render($cludo_search_search_form); ?>
<div class="container-inline">
  <?php print $search_form_complete; ?>
</div>
<!-- Cludo search results starts -->
<div id="cludo-search-results">
    <div class="container">
        <div class="row">
            <div class="col-xs-3">
                <div class="search-filters"></div>
            </div>
            <div class="col-xs-9">
                <div class="search-result-count"></div>
                <div class="search-did-you-mean"></div>
                <div class="search-results"></div>
            </div>
        </div>
    </div>
</div>
<!-- Cludo search results ends -->