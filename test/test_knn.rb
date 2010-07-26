require "test/unit"
require "knn"
require "shoulda"

class TestKnn < Test::Unit::TestCase
  context "KNN" do
    setup do
      @knn = Knn.new([[1,2,3], [4,2,1]])
    end

    should "initialize" do
      Knn.new(Array.new)
    end

    should "raise error if initialized without array" do
      assert_raise(TypeError) { Knn.new("string") }
    end

    should "assign @data" do
      puts @knn.inspect
    end

    should "return itself" do
      puts @knn.nearest_neighbours([1,2,3], 4).inspect
    end
  end
end
