#include "projlogging.hpp"
#include "common.hpp"

namespace projectile_logging
{
boost::unordered_flat_map<u_int16_t, Vector> prevloc;

void Update()
{
    for (auto const &ent : entity_cache::valid_ents)
    {
        const uint16_t curr_idx = ent->m_IDX;

        if (ent->m_Type() == ENTITY_PROJECTILE)
        {
            if (tickcount % 20 == 0)
            {
                Vector abs_orig = RAW_ENT(ent)->GetAbsOrigin();
                float movement  = prevloc[curr_idx].DistTo(abs_orig);

                logging::Info("movement: %f", movement);

                prevloc[curr_idx] = abs_orig;
                const Vector &v   = ent->m_vecVelocity;
                Vector eav;
                velocity::EstimateAbsVelocity(RAW_ENT(ent), eav);

                logging::Info("%d [%s]: CatVelocity: %.2f %.2f %.2f (%.2f) | "
                              "EAV: %.2f %.2f %.2f (%.2f)",
                              curr_idx, RAW_ENT(ent)->GetClientClass()->GetName(), v.x, v.y, v.z, v.Length(), eav.x, eav.y, eav.z, eav.Length());
            }
        }
    }
}
} // namespace projectile_logging
