#include <stxxl/vector>

namespace settings {

    const long int required_size = 1024 * 1024;
    const long int stxxl_disk_size = required_size * 10;

    int sleep_time(int i){
        return i%5+1;
    }

    void config_stxxl_disk(stxxl::config *cfg){
        stxxl::disk_config disk1("/tmp/stxxl.tmp", settings::stxxl_disk_size, "syscall autogrow delete_on_exit");
        disk1.direct = stxxl::disk_config::DIRECT_ON; // force O_DIRECT
        cfg->add_disk(disk1);
    }

}
