/**
 * @file
 * Task: Default.
 */

module.exports = function (gulp, plugins, options) {
  'use strict';

  gulp.task('default', gulp.series('build'));
};
