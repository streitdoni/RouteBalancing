//
// Copyright (C) 2014 OpenSim Ltd.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

package src.node;

import inet.node.inet.WirelessHost;
import src.routing.aodvStandard.AODVStandardRouting;


//
// It models a ~WirelessHost extended with ~AODVRouting submodule.
//
// AODV is an on-demand MANET routing protocol. Each node
// works similar to a 'router': they manage their own routing
// tables, send request for routes and consult the IP layer via
// Netfilter hooks for data forwarding.
//
// Scenerios where AODV routing is desired use this module as a
// host module.
//
// For more info about AODVRouting, see the corresponding module:
// ~AODVRouting and its C++ implementation with the same name.
//
// The AODV v.2 (known as DYMO) is also implemented: ~DYMO,
// ~DYMORouter.
//
module AODVStandardRouter extends WirelessHost
{
    parameters:
        @display("i=device/cellphone");
        forwarding = true;
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");
        
    submodules:
        aodvStandard: AODVStandardRouting {
            @display("p=558,307");
        }
    connections:
        aodvStandard.ipOut --> networkLayer.transportIn++;
        aodvStandard.ipIn <-- networkLayer.transportOut++;
}
