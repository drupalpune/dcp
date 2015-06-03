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

<div class="panel-display cygnus panel-layout clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container preface clearfix panel-panel">
    <div class="container-inner preface-inner panel-panel-inner">
      <?php print $content['preface']; ?>
    </div>
  </div>

  <div class="container content clearfix">
    <div class="container-inner content-inner panel-panel-inner">
      <div class="column-content-region content column panel-panel">
        <div class="column-content-region-inner content-inner column-inner panel-panel-inner">
          <?php print $content['content']; ?>
        </div>
      </div>
    </div>
  </div>

  <div class="container footer clearfix panel-panel">
    <div class="container-inner footer-inner panel-panel-inner">
      <?php print $content['footer']; ?>
    </div>
  </div>
  
</div><!-- /.sutro -->
