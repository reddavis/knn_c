## -*- ruby -*-
#
#require 'rubygems'
#require 'hoe'
#require 'rake/extensiontask'
#
#Hoe.spec 'knn' do
#  developer('Red Davis', 'reddavis@gmail.com')
#  self.extra_dev_deps << ['rake-compiler', '>= 0']
#  self.spec_extras = { :extensions => ["ext/knn/extconf.rb"] }
#
#  Rake::ExtensionTask.new('knn', spec) do |ext|
#    ext.lib_dir = File.join('lib', 'knn')
#  end
#end
#
#Rake::Task[:test].prerequisites << :compile

require 'rubygems'
require 'rake'
require 'rake/extensiontask'

begin
  require 'jeweler'
  Jeweler::Tasks.new do |gem|
    gem.name = "knn_c"
    gem.summary = %Q{Knn in C}
    gem.description = %Q{Knn in C}
    gem.email = "reddavis@gmail.com"
    gem.homepage = "http://github.com/reddavis/knnC"
    gem.files = FileList['lib/**/*']
    gem.extensions = FileList['ext/**/extconf.rb']
    gem.authors = ["reddavis"]
    # gem is a Gem::Specification... see http://www.rubygems.org/read/chapter/20 for additional settings
  end
  Jeweler::GemcutterTasks.new
rescue LoadError
  puts "Jeweler (or a dependency) not available. Install it with: gem install jeweler"
end

require 'rake/testtask'
Rake::TestTask.new(:test) do |test|
  test.libs << 'lib' << 'test'
  test.pattern = 'test/**/test_*.rb'
  test.verbose = true
end

Rake::ExtensionTask.new('knn_c') do |ext|
  ext.lib_dir = File.join('lib', 'knn_c')
end

task :test => :check_dependencies
task :default => :test

Rake::Task[:test].prerequisites << :compile