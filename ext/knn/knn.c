#include <ruby.h>

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

static VALUE rb_knn_nearest_neighbour(VALUE self, VALUE input_data, VALUE k) {

  return rb_iv_get(self, "@data");
}

void Init_knn() {
  VALUE knn_class = rb_define_class("Knn", rb_cObject);
  rb_define_method(knn_class, "initialize", rb_knn_new, 1);
  rb_define_method(knn_class, "nearest_neighbours", rb_knn_nearest_neighbour, 2);
}