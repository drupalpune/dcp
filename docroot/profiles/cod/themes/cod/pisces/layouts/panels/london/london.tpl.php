<?php
/**
 * @file
 * Template for London
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display london clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <header class="container header clearfix panel-panel grid-12">
    <div class="container-inner header-inner panel-panel-inner">
      <?php print $content['header']; ?>
    </div>
  </header>

  <div class="container headercontent clearfix panel-panel grid-12">
    <div class="container-inner headercontent-inner panel-panel-inner">
      <?php print $content['headercontent']; ?>
    </div>
  </div>
  
  <div class="container column-content clearfix">
    <div class="container-inner column-content panel-panel-inner">
    <div class="column-content-region column1 column panel-panel grid-6">
      <div class="column-content-region-inner column1-inner column-inner panel-panel-inner">
        <?php print $content['column1']; ?>
      </div>
    </div>
    <div class="column-content-region column2 column panel-panel grid-6">
      <div class="column-content-region-inner column2-inner column-inner panel-panel-inner">
        <?php print $content['column2']; ?>
      </div>
    </div>
    </div>
  </div>



  <div class="container footer clearfix panel-panel grid-12">
    <div class="container-inner footer-inner panel-panel-inner">
      <?php print $content['footer']; ?>
    </div>
  </div>
  
</div><!-- /.sutro -->
