#include <ruby.h>
#include <stdio.h>
#include <math.h>

double euclidean_distance(VALUE vector_one, VALUE vector_two);

/*

def initialize(data)
  raise TypeError unless data.is_a?(Array)
  @data = data
end

*/
static VALUE rb_knn_new(VALUE self, VALUE data) {
  Check_Type(data, T_ARRAY); // Check its an array
  rb_iv_set(self, "@data", data); // Set data

  return self;
}

// Something like:
/*

def nearest_neighbours(input, k=4)
  calculated_distances = []

  @data.each_with_index do |datum, index|
    distance = input.euclidean_between(datum)
    calculated_distances << [index, distance, datum]
  end

  calculated_distances.sort {|x, y| x[1] <=> y[1]}.first(k)
end

*/
static VALUE rb_knn_nearest_neighbour(VALUE self, VALUE input_data, VALUE k) {
  VALUE data = rb_iv_get(self, "@data");
  VALUE results = rb_ary_new(); // Results go here

  long data_length = RARRAY(data)->len;

  int data_index; // index for @data

  for(data_index = 0; data_index <= data_length; data_index++) {

    VALUE result = rb_ary_new();
    VALUE datum = RARRAY(data)->ptr[data_index];

    VALUE distance = rb_float_new(euclidean_distance(input_data, datum));

    //rb_ary_push(result, data_index);
    rb_ary_push(result, distance);
    //rb_ary_push(result, datum);

    rb_ary_push(results, result);
  } // for(data_index)

  return results;
}

double euclidean_distance(VALUE vector_one, VALUE vector_two) {
  return 1.123;
}

void Init_knn() {
  VALUE knn_class = rb_define_class("Knn", rb_cObject);
  rb_define_method(knn_class, "initialize", rb_knn_new, 1);
  rb_define_method(knn_class, "nearest_neighbours", rb_knn_nearest_neighbour, 2);
}