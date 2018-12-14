# gen_errors




# cache clear #
sync; echo 1 > /proc/sys/vm/drop_caches
sync; echo 2 > /proc/sys/vm/drop_caches



# Swap Space Clear #
swapoff -a && swapon -a


