<?php

/**
 * @file
 * Omega theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['member_for'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see template_preprocess_user_profile()
 */
?>
<article<?php print $attributes; ?>>
  <?php if(isset($user_profile['user_picture'])): ?>
    <?php print render($user_profile['user_picture']); ?>
  <?php endif; ?>
  <?php if(isset($user_profile['field_profile_first']) && isset($user_profile['field_profile_last'])): ?>
    <h2><?php print $user_profile['field_profile_first']['#items'][0]['safe_value'] . ' ' . $user_profile['field_profile_last']['#items'][0]['safe_value']; ?></h2>
  <?php endif; ?>
  <?php if(isset($user_profile['field_profile_job_title']) && isset($user_profile['field_profile_org'])): ?>
    <h3><?php print $user_profile['field_profile_job_title']['#items'][0]['safe_value'] . ' at ' . $user_profile['field_profile_org']['#items'][0]['safe_value']; ?></h3>
  <?php endif; ?>
  <?php if(isset($user_profile['field_profile_bio'])): ?>
    <p><?php print $user_profile['field_profile_bio']['#items'][0]['safe_value']; ?></p>
  <?php endif; ?>
</article>
