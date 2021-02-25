my $in = shift ;
my $name = shift || die "Need name" ;
while (1) {
   system("./genrand $in > t$$.sched") ;
   my $v = `./main $in t$$.sched` ;
   chomp $v ;
   $v =~ s/Final score // ;
   if ($v > $hi) {
      $hi = $v ;
      print "Score now $v\n" ;
      system("cp t$$.sched $name-$hi.sched") ;
   }
}
