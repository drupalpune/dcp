<?php
/**
 * @file
 * Main snippet template
 *
 * Variables available:
 * - $title: The title of the content
 * - $content: The actual content
 * - $admin_links: Administrative links associated with the content
 */
?>
<div<?php print $attributes; ?>>
  <?php if (isset($admin_links) && $admin_links): ?>
    <?php print $admin_links; ?>
  <?php endif; ?>

  <?php print render($title_prefix); ?>
  <?php if (isset($title) && !empty($title)): ?>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </div>

</div>
