# -*- ruby -*-

require 'rubygems'
require 'hoe'
require 'rake/extensiontask'

Hoe.spec 'knn' do
  developer('Red Davis', 'reddavis@gmail.com')
  self.extra_dev_deps << ['rake-compiler', '>= 0']
  self.spec_extras = { :extensions => ["ext/knn/extconf.rb"] }

  Rake::ExtensionTask.new('knn', spec) do |ext|
    ext.lib_dir = File.join('lib', 'knn')
  end
end

Rake::Task[:test].prerequisites << :compile