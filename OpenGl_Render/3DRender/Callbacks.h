#pragma once

static void glfw_error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);
	throw ("glfw error :(");
}