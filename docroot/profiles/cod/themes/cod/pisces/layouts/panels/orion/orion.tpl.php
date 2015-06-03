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

<div class="panel-display orion panel-layout clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container banner clearfix panel-panel">
    <div class="container-inner banner-inner panel-panel-inner">
      <?php print $content['banner']; ?>
    </div>
  </div>

  <div class="container header clearfix">
    <div class="container-inner header-inner panel-panel-inner">
      <div class="column-content-region left-header column panel-panel ">
        <div class="column-content-region-inner left-header-inner column-inner panel-panel-inner">
          <?php print $content['left_header']; ?>
        </div>
      </div>
      <div class="column-content-region right-header column panel-panel">
        <div class="column-content-region-inner right-header-inner column-inner panel-panel-inner">
          <?php print $content['right_header']; ?>
        </div>
      </div>
    </div>
  </div>

  <div class="container preface clearfix panel-panel">
    <div class="container-inner preface-inner panel-panel-inner">
      <?php print $content['preface']; ?>
    </div>
  </div>

  <div class="container content clearfix">
    <div class="container-inner content-inner panel-panel-inner">
      <div class="column-content-region left-content column panel-panel ">
        <div class="column-content-region-inner left-content-inner column-inner panel-panel-inner">
          <?php print $content['left_content']; ?>
        </div>
      </div>
      <div class="column-content-region right-content column panel-panel">
        <div class="column-content-region-inner right-content-inner column-inner panel-panel-inner">
          <?php print $content['right_content']; ?>
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
