#include "test.h"
#include "util.h"

int main(int argc, char **argv) {
	assert_err_list_t *assert_err_list = assert_err_list_new();
	assert_expr(assert_err_list, strchrcnt("I am happy.", 'a') == 2, "strchrcnt test 0", "count mismatch"); 
	assert_expr(assert_err_list, strchrcnt("I screm loud.", 's') == 1, "strchrcnt test 1", "count mismatch"); 
	assert_expr(assert_err_list, strchrcnt("Doggo borks.", 'a') == 0, "strchrcnt test 2", "count mismatch"); 
	
	assert_expr(assert_err_list, is_possible("whoops", "whoopsie", 4, true), "is_possible test 0", "whoops");
	assert_expr(assert_err_list, !is_possible("whoops", "whopsie", 4, true), "is_possible test 1", "whoops");
	assert_expr(assert_err_list, is_possible("whoops", "whopsie", 4, false), "is_possible test 2", "whoops");
	assert_expr(assert_err_list, !is_possible("bork", "borked", 5, true), "is_possible test 3", "whoops");

	assert_err_list_dump(assert_err_list);
	assert_err_list_destroy(assert_err_list);
}
