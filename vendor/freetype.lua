project "freetype"
    kind "StaticLib"
    language "C"
    warnings "Off"
    defines { "FT2_BUILD_LIBRARY" }
    includedirs { "freetype/include" }

    local s = "freetype/src/"
    files {
        s.."base/ftsystem.c", s.."base/ftdebug.c", s.."base/ftinit.c", s.."base/ftbase.c",
        s.."base/ftbbox.c", s.."base/ftbdf.c", s.."base/ftbitmap.c", s.."base/ftcid.c",
        s.."base/ftfstype.c", s.."base/ftgasp.c", s.."base/ftglyph.c", s.."base/ftgxval.c",
        s.."base/ftmm.c", s.."base/ftotval.c", s.."base/ftpatent.c", s.."base/ftpfr.c",
        s.."base/ftstroke.c", s.."base/ftsynth.c", s.."base/fttype1.c", s.."base/ftwinfnt.c",
        s.."autofit/autofit.c", s.."bdf/bdf.c", s.."cache/ftcache.c", s.."cff/cff.c",
        s.."cid/type1cid.c", s.."gzip/ftgzip.c", s.."lzw/ftlzw.c", s.."pcf/pcf.c",
        s.."pfr/pfr.c", s.."psaux/psaux.c", s.."pshinter/pshinter.c", s.."psnames/psnames.c",
        s.."raster/raster.c", s.."sdf/sdf.c", s.."sfnt/sfnt.c", s.."smooth/smooth.c",
        s.."svg/svg.c", s.."truetype/truetype.c", s.."type1/type1.c", s.."type42/type42.c",
        s.."winfonts/winfnt.c",
    }
