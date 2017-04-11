var gulp = require('gulp');
var autoprefixer = require('gulp-autoprefixer');
var compass = require('gulp-compass');
var jshint = require('gulp-jshint');
var imagemin = require('gulp-imagemin');
var cleanCSS = require('gulp-clean-css');
var rename = require('gulp-rename');
var browserSync = require('browser-sync').create();

gulp.task('images', function() {
    return gulp.src('images/*.jpg')
        .pipe(imagemin())
        .pipe(gulp.dest('images/'));
});

gulp.task('jshint', function() {
    return gulp.src('js/*.js')
        .pipe(jshint())
        .pipe(jshint.reporter('jshint-stylish'));
});

gulp.task('browserSync', function() {
    browserSync.init(null, {
        proxy: 'http://internship.new'
    })
})



gulp.task('compass', function() {
    gulp.src('scss/**/*.scss')
        .pipe(compass({
            config_file: 'config.rb',
            css: 'css',
            sass: 'scss'
        }))
        .pipe(gulp.dest('css/'));
});

gulp.task('styles', function() {

    gulp.src(['css/style.css'])
        .pipe(autoprefixer({
            browsers: ['last 2 version', 'safari 5', 'ie 8', 'ie 9', 'opera 12.1', 'ios 6', 'android 4'],
            cascade: false
        }))
        .pipe(gulp.dest('css/'))
        .pipe(browserSync.reload({
            stream: true
        }))
});

gulp.task('minifycss', function() {
    return gulp.src('css/**/*.css')
        .pipe(cleanCSS({ compatibility: 'ie8' }))
        .pipe(rename({ suffix: '.min' }))
        .pipe(gulp.dest('css'));
});


gulp.task('default', ['compass', 'browserSync', 'styles', 'images'], function() {
    gulp.watch("scss/**/*.scss", ['compass']);
    gulp.watch("js/*.js", ['jshint']);
    gulp.watch("css/*.css", ['styles']);
});
