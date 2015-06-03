<?php
/**
 * @file
 * Panels Template: Rome
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>
<div id="wx-wrapper"><!-- Wrapper in master JSP -->
  <div class="panel-display ad-rail rome clearfix ">
      <header id="wx-top-wrapper" class="column-content-region content-header clearfix panel-panel"> <!-- Wrapper in master JSP -->
        <div class="content-header-inner column-content-region-inner column-inner container-inner panel-panel-inner">
          <?php print $content['contentheader']; ?>
        </div>
      </header>
      <div id="wx-mid-wrap" >
            <div id="wx-main" class="content-container container grid-12">
              <div class="content-container-inner container-inner clearfix">     
                <div class="content-container-column-container panel-panel clearfix">
                  <div class="content-container-column-container-inner">
                   
                    <div class="column-content-region left-rail clearfix panel-panel grid-3">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['left_rail']; ?>
                      </div>
                    </div>

                    
                    <?php if (!empty($content['content_row_1'])): ?>
                      <div class="column-content-region content-row-1 main-content clearfix panel-panel grid-9">
                        <div class="column-content-region-inner region-inner">
                          <?php print $content['content_row_1']; ?>
                        </div>
                      </div>
                    <?php endif; ?>
                    <?php if (!empty($content['content_row_2'])): ?>
                    <div class="column-content-region content-row-2 clearfix panel-panel grid-12">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_2']; ?>
                      </div>
                    </div>
                    <?php endif; ?>
                    <?php if (!empty($content['content_row_3'])): ?>
                    <div class="column-content-region content-row-3 clearfix panel-panel grid-12">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_3']; ?>
                      </div>
                    </div>
                    <?php endif; ?>
                    <?php if (!empty($content['content_row_4'])): ?>
                    <div class="column-content-region content-row-4 clearfix panel-panel grid-12">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_4']; ?>
                      </div>
                    </div>
                    <?php endif; ?>
                    <?php if (!empty($content['content_row_5'])): ?>
                    <div class="column-content-region content-row-5 clearfix panel-panel grid-12">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_5']; ?>
                      </div>
                    </div>
                    <?php endif; ?>
                    <?php if (!empty($content['content_row_6'])): ?>
                    <div class="column-content-region content-row-6 clearfix panel-panel grid-12">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_6']; ?>
                      </div>
                    </div>
                    <?php endif; ?>
                    <?php if (!empty($content['content_row_7'])): ?>
                    <div class="column-content-region content-row-7 clearfix panel-panel grid-12">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_7']; ?>
                      </div>
                    </div>
                    <?php endif; ?>
                    <?php if (!empty($content['content_row_8'])): ?>
                      <div class="column-content-region content-row-8 main-content clearfix panel-panel grid-9">
                        <div class="column-content-region-inner region-inner">
                          <?php print $content['content_row_8']; ?>
                        </div>
                      </div>
                    <?php endif; ?>
                  </div>
                </div><!-- /.content-container-column-container -->
              </div>
            </div><!-- end #wx-main -->
            
            <div id="wx-rail" class="sidebar column-content-region column container panel-panel ">
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
  </div><!-- /.rome -->
</div><!-- End Wrapper in master JSP -->
