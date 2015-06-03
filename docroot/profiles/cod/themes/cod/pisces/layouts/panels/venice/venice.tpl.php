<?php
/**
 * @file
 * Template for Department Landing Pages.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display venice panel-layout clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container banner clearfix panel-panel">
    <div class="container-inner banner-inner panel-panel-inner">
      <?php print $content['banner']; ?>
    </div>
  </div>
  <div class="container overlay clearfix panel-panel">
    <div class="container-inner overlay-inner panel-panel-inner">
      <?php print $content['overlay']; ?>
    </div>
  </div>

  <div class="container headercontent clearfix panel-panel">
    <div class="container-inner headercontent-inner panel-panel-inner">
      <?php print $content['headercontent']; ?>
    </div>
  </div>
  
  <div class="container content clearfix">
    <div class="container-inner content-inner panel-panel-inner">
      <div class="column-content-region content-column-1 column panel-panel ">
        <div class="column-content-region-inner content-column--inner column-inner panel-panel-inner">
          <?php print $content['column1']; ?>
        </div>
      </div>
      <div class="column-content-region content-column-2 column panel-panel">
        <div class="column-content-region-inner content-column-2-inner column-inner panel-panel-inner">
          <?php print $content['column2']; ?>
        </div>
      </div>
    </div>
  </div>
  
  <div class="container footer clearfix">
    <div class="container-inner footer-inner panel-panel-inner">

      <div class="column-content-region footer-column-1 panel-panel ">
        <div class="footer-content-region-inner footer-column-1-inner footer-column-inner panel-panel-inner">
          <?php print $content['footer_column_1']; ?>
        </div>
      </div>
      <div class="footer-content-region footer-column-2 panel-panel">
        <div class="footer-content-region-inner footer-column-2-inner footer-column-inner panel-panel-inner">
          <?php print $content['footer_column_2']; ?>
        </div>
      </div>

    </div>
  </div>

  
</div><!-- /.sutro -->
