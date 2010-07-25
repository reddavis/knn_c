#include <ruby.h>

void knn_delete() {
  // WTF to put in here
}

void knn_mark() {
  // WTF to put in here
}

/*

def initialize(data)
  raise TypeError unless data.is_a?(Array)
  @data = data
end

*/
static VALUE rb_knn_new(VALUE self, VALUE data) {
  Check_Type(data, T_ARRAY); // Check its an array

  VALUE klass = Data_Wrap_Struct(self, knn_mark, knn_delete, 1); // WTF is the 0 and 1 for?
  rb_iv_set(klass, "@data", data);

  return klass;
}

void Init_knn() {
  VALUE knn_class = rb_define_class("Knn", rb_cObject);
  rb_define_singleton_method(knn_class, "new", rb_knn_new, 1);
}