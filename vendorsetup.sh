for rom in rr dot lineage cerberus aosp cos havoc lotus
do
  for variant in user userdebug eng
  do
    add_lunch_combo ${rom}_on7xelte-${variant}
  done
done
