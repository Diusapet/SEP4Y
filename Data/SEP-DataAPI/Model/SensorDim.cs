﻿using System;
using System.Collections.Generic;

namespace SEP_DataAPI.Model
{
    public partial class SensorDim
    {
        public SensorDim()
        {
            Facts = new HashSet<Facts>();
        }

        public int SensorsId { get; set; }
        public double? TempC { get; set; }
        public double? TempF { get; set; }
        public decimal? Co2 { get; set; }

        public virtual ICollection<Facts> Facts { get; set; }
    }
}
