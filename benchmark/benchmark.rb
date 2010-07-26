require 'rubygems'
require 'knn'
require 'knn_c'
require 'benchmark'

data = Array.new(99999) { Array.new(4) { rand } }

knn = KNN.new(data)
knn_c = KnnC.new(data)


Benchmark.bm do |x|
  x.report("Ruby") { knn.nearest_neighbours([1,2,3,4], 4) }
  x.report("C") { knn_c.nearest_neighbours([1,2,3,4], 4) }
end

#        user      system      total        real
#Ruby  2.800000   0.020000   2.820000 (  2.838406)
#C     0.160000   0.010000   0.170000 (  0.170568)
