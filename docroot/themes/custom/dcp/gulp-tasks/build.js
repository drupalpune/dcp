/**
 * @file
 * Task: Build.
 */

module.exports = function (gulp, plugins, options) {
  'use strict';

  gulp.task('build', gulp.series('compile:sass', gulp.parallel('lint:css-with-fail')));

  gulp.task('build:dev', gulp.series('compile:sass', gulp.parallel('lint:css')));

};
