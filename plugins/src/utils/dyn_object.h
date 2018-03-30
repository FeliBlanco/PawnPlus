#ifndef DYN_OBJECT_H_INCLUDED
#define DYN_OBJECT_H_INCLUDED

#include "sdk/amx/amx.h"
#include <memory>
#include <string>
#include <cstring>

class dyn_object
{
	bool is_array;
	union{
		cell cell_value;
		size_t array_size;
	};
	std::unique_ptr<cell[]> array_value;
	std::string tag_name;
	std::string find_tag(AMX *amx, cell tag_id) const;

public:
	dyn_object(AMX *amx, cell value, cell tag_id);
	dyn_object(AMX *amx, cell *arr, size_t size, cell tag_id);
	dyn_object(const dyn_object &obj);
	dyn_object(dyn_object &&obj);
	bool check_tag(AMX *amx, cell tag_id) const;
	bool get_cell(size_t index, cell &value) const;
	size_t get_array(size_t index, cell *arr, size_t maxsize) const;
	bool set_cell(size_t index, cell value);
	cell get_tag(AMX *amx) const;
	cell store(AMX *amx) const;
	void load(AMX *amx, cell amx_addr);
	size_t get_size() const;
	cell &operator[](size_t index);
	dyn_object &operator=(const dyn_object &obj);
	dyn_object &operator=(dyn_object &&obj);
};

#endif