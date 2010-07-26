require "test_helper"

class TestKnnC < Test::Unit::TestCase
  context "KNNC" do
    setup do
      @knn = KnnC.new([[1,2,3], [4,2,1], [22,22,99], [4,6,1]])
    end

    should "initialize" do
      KnnC.new(Array.new)
    end

    should "raise error if initialized without array" do
      assert_raise(TypeError) { KnnC.new("string") }
    end

    should "return an array" do
      assert_kind_of Array, @knn.nearest_neighbours([1,2,3], 4)
    end

    # TODO
    # Test for correct answer ;)
  end
end
