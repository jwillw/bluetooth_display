#include <zephyr/bluetooth/services/ots.h>

static int ots_obj_created(
	bt_ots *ots, bt_conn *conn, uint64_t id,
	const bt_ots_obj_add_param *add_param,
	bt_ots_obj_created_desc    *created_desc
) {
	return -ENOSYS;
}

static int ots_obj_deleted(bt_ots *ots, bt_conn *conn, uint64_t id) {
	return -ENOSYS;
}

static void ots_obj_selected(bt_ots *ots, bt_conn *conn, uint64_t id) {}

static ssize_t ots_obj_read(
	bt_ots *ots, bt_conn *conn, uint64_t id, void **data, size_t len,
	off_t offset
) {
	return -ENOSYS;
}

static ssize_t ots_obj_write(
	bt_ots *ots, bt_conn *conn, uint64_t id, const void *data, size_t len,
	off_t offset, size_t rem
) {
	return -ENOSYS;
}

static void ots_obj_name_written(
	bt_ots *ots, bt_conn *conn, uint64_t id, const char *cur_name,
	const char *new_name
) {}

static int ots_obj_cal_checksum(
	bt_ots *ots, bt_conn *conn, uint64_t id, off_t offset, size_t len,
	void **data
) {
	return -ENOSYS;
}

static bt_ots_cb ots_cb = {
	.obj_created      = ots_obj_created,
	.obj_deleted      = ots_obj_deleted,
	.obj_selected     = ots_obj_selected,
	.obj_read         = ots_obj_read,
	.obj_write        = ots_obj_write,
	.obj_name_written = ots_obj_name_written,
	.obj_cal_checksum = ots_obj_cal_checksum
};

int ots_init() {
	int     err;
	bt_ots *ots = bt_ots_free_instance_get();
	if (ots == NULL) return -ENOMEM;

	bt_ots_init_param ots_init = {
		.features = {.oacp = BIT(BT_OTS_OACP_FEAT_WRITE), .olcp = 0},
		.cb       = &ots_cb
	};
	err = bt_ots_init(ots, &ots_init);
	if (err) return err;
	return 0;
}
