<?php
/**
 * @file
 * Panels Template: Paris
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>
<div id="wx-wrapper"><!-- Wrapper in master JSP -->


<div class="panel-display ad-rail paris clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  
  <header id="wx-top-wrapper" class="column-content-region content-header clearfix panel-panel"> <!-- Wrapper in master JSP -->
    <div class="content-header-inner column-content-region-inner column-inner container-inner panel-panel-inner">
      <?php print $content['contentheader']; ?>
    </div>
  </header>
  <div id="wx-mid-wrap" >
  <div id="wx-main" class="content-container container">
    <span class="content-container-inner container-inner clearfix">
      
      <div class="content-container-column-container panel-panel  grid-12 clearfix">
        <span class="content-container-column-container-inner">
         
          <div class="column-content-region content-row-1 clearfix panel-panel grid-12">
            <div class="column-content-region-inner region-inner">
              <?php print $content['content_row_1']; ?>
            </div>
          </div>
          <div class="column-content-region content-row-2 clearfix panel-panel grid-12">
            <div class="column-content-region-inner region-inner">
              <?php print $content['content_row_2']; ?>
            </div>
          </div>
          <div class="column-content-region content-row-3 clearfix panel-panel grid-12">
            <div class="column-content-region-inner region-inner">
              <?php print $content['content_row_3']; ?>
            </div>
          </div>
          <div class="column-content-region content-row-4 clearfix panel-panel grid-12">
            <div class="column-content-region-inner region-inner">
              <?php print $content['content_row_4']; ?>
            </div>
          </div>
          <div class="column-content-region content-row-5 clearfix panel-panel grid-12">
            <div class="column-content-region-inner region-inner">
              <?php print $content['content_row_5']; ?>
            </div>
          </div>
          <div class="column-content-region content-row-6 clearfix panel-panel grid-12">
            <div class="column-content-region-inner region-inner">
              <?php print $content['content_row_6']; ?>
            </div>
          </div>
          <div class="column-content-region content-row-7 clearfix panel-panel grid-12">
            <div class="column-content-region-inner region-inner">
              <?php print $content['content_row_7']; ?>
            </div>
          </div>
          <div class="column-content-region content-row-8 clearfix panel-panel grid-12">
            <div class="column-content-region-inner region-inner">
              <?php print $content['content_row_8']; ?>
            </div>
          </div>


        </span>
      </div><!-- /.content-container-column-container -->
    </span>
  </div><!-- end #wx-main -->
  
  <div id="wx-rail" class="sidebar column-content-region column container panel-panel  grid-12">
    <div class="sidebar-inner column-content-region-inner column-inner container-inner panel-panel-inner">
      <?php print $content['sidebar']; ?>
    </div>
  </div>
</div><!-- end wx-mid-wrap -->
  <div id="wx-bottom-wrap" class="footer column-content-region column container panel-panel">
    <div class="footer-inner column-content-region-inner column-inner container-inner panel-panel-inner">
      <?php print $content['footer']; ?>
    </div>
  </div>
  
</div><!-- /.paris -->
<div id="wx-wrapper"><!-- End Wrapper in master JSP -->
