hm1 -input spline01_bezier.txt -gui -curve_tessellation 30
hm1 -input spline02_bspline.txt -gui -curve_tessellation 30
hm1 -input spline01_bezier.txt -output_bezier output01_bezier.txt
hm1 -input spline02_bspline.txt -output_bspline output02_bspline.txt
hm1 -input output01_bezier.txt -gui -curve_tessellation 30
hm1 -input output01_bspline.txt -gui -curve_tessellation 30
hm1 -input output02_bezier.txt -gui -curve_tessellation 30
hm1 -input output02_bspline.txt -gui -curve_tessellation 30
hm1 -input spline03_bezier.txt -gui -curve_tessellation 30
hm1 -input spline04_bspline.txt -gui -curve_tessellation 30
hm1 -input spline05_bspline_dups.txt -gui -curve_tessellation 30
hm1 -input spline06_torus.txt -curve_tessellation 4 -gui
hm1 -input spline06_torus.txt -curve_tessellation 4 -revolution_tessellation 10 -output torus_low.obj
hm1 -input spline06_torus.txt -curve_tessellation 30 -revolution_tessellation 60 -output torus_high.obj

hm1 -input spline07_vase.txt -curve_tessellation 4 -output_bspline output07_edit.txt -gui
hm1 -input output07_edit.txt -curve_tessellation 4 -revolution_tessellation 10 -output vase_low.obj
hm1 -input output07_edit.txt -curve_tessellation 10 -revolution_tessellation 60 -output vase_high.obj

hm1 -input spline08_bezier_patch.txt -gui
hm1 -input spline08_bezier_patch.txt -patch_tessellation 4 -output patch_low.obj
hm1 -input spline08_bezier_patch.txt -patch_tessellation 10 -output patch_med.obj
hm1 -input spline08_bezier_patch.txt -patch_tessellation 40 -output patch_high.obj