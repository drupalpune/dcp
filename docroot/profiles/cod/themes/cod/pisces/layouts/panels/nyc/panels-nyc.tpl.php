<?php
/**
 * @file
 * Panels Template: NYC
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>
<div id="wx-wrapper"><!-- Wrapper in master JSP -->
  <div class="panel-display ad-rail nyc clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
      
      <div id="wx-top-wrap" class="top-container container">
        <div class="top-container-inner container-inner clearfix">   
          <header id="header" class="header column-content-region clearfix panel-panel"> <!-- Wrapper in master JSP -->
            <div class="header-inner column-content-region-inner region-inner">
              <?php print $content['header']; ?>
            </div>
          </header>
        </div>
      </div>


      <div id="wx-mid-wrap" class="content-container container">
        <div class="content-container-inner container-inner clearfix">     
              
              <?php if (!empty($content['banner'])): ?>    
                  <div id="banner" class="banner column-content-region clearfix panel-panel"> <!-- Wrapper in master JSP -->
                    <div class="banner-inner column-content-region-inner region-inner">
                      <?php print $content['banner']; ?>
                    </div>
                  </div>
              <?php endif; ?>
              <?php if (!empty($content['top_stories'])): ?>
                    <div class="top-stories column-content-region main-content clearfix panel-panel">
                      <div class="top-stories-inner column-content-region-inner region-inner">
                        <?php print $content['top_stories']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['content_row_1'])): ?>
                    <div class="content-row-1 column-content-region clearfix panel-panel">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_1']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['content_row_2'])): ?>
                    <div class="content-row-2 column-content-region clearfix panel-panel">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_2']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['promo'])): ?>
                    <div class="promo column-content-region  clearfix panel-panel">
                      <div class="promo-inner column-content-region-inner region-inner">
                        <?php print $content['promo']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['content_row_3'])): ?>
                    <div class="content-row-3 column-content-region clearfix panel-panel">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_3']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['content_row_4'])): ?>
                    <div class="content-row-4 column-content-region clearfix panel-panel">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_4']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['content_row_5'])): ?>
                    <div class="content-row-5 column-content-region clearfix panel-panel">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_5']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['content_row_6'])): ?>
                    <div class="content-row-6 column-content-region clearfix panel-panel">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_6']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['content_row_7'])): ?>
                    <div class="content-row-7 column-content-region clearfix panel-panel">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_7']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['content_row_8'])): ?>
                    <div class="content-row-8 column-content-region clearfix panel-panel">
                      <div class="column-content-region-inner region-inner">
                        <?php print $content['content_row_8']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['left_rail'])): ?>
                    <div class="left-rail column-content-region panel-panel grid-3">
                      <div class="left-rail-inner column-content-region-inner region-inner">
                        <?php print $content['left_rail']; ?>
                      </div>
                    </div>
              <?php endif; ?>
              <?php if (!empty($content['partners'])): ?>
                  <div id="partners" class="partners column-content-region panel-panel">
                    <div class="partners-inner column-content-region-inner region-inner">
                      <?php print $content['partners']; ?>
                    </div>
                  </div>
              <?php endif; ?> 
          </div>    
      </div><!-- end wx-mid-wrap -->

    <div id="wx-bottom-wrap" class="bottom-container container">
      <div class="bottom-container-inner container-inner clearfix">     
        <footer id="panel-footer" class="footer column-content-region panel-panel">
            <div class="footer-inner column-content-region-inner region-inner">
              <?php print $content['footer']; ?>
            </div>
          </footer>
      </div>
    </div>

  </div><!-- /.nyc -->
</div><!-- End Wrapper in master JSP -->
