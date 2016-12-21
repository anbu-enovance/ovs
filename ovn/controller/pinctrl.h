
/* Copyright (c) 2015, 2016 Nicira, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PINCTRL_H
#define PINCTRL_H 1

#include <stdint.h>

#include "openvswitch/meta-flow.h"

struct hmap;
struct lport_index;
struct ovsrec_bridge;
struct controller_ctx;
struct sbrec_chassis;

void pinctrl_init(void);
void pinctrl_run(const struct lport_index *,
                 const struct ovsrec_bridge *,
                 const struct sbrec_chassis *,
                 struct hmap *local_datapaths);
void pinctrl_wait(void);
void pinctrl_destroy(void);
void pinctrl_put_mac_binding_for_each(void (*iteration_cb)(void *private_data,
                                                           uint32_t port_key,
                                                           uint32_t dp_key,
                                                           const char *ip_s,
                                                           const struct eth_addr *mac),
                                      void *private_data);

#endif /* ovn/pinctrl.h */
